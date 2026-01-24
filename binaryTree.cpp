#include <bits/stdc++.h>
using namespace std;

/* ---------------- Tree Definition ---------------- */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* =================================================
   1. Preorder Traversal (Root, Left, Right)
   ================================================= */
void preorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
}

/* =================================================
   2. Inorder Traversal (Left, Root, Right)
   ================================================= */
void inorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

/* =================================================
   3. Postorder Traversal (Left, Right, Root)
   ================================================= */
void postorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
}

/* =================================================
   4. Level Order Traversal
   ================================================= */
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        vector<int> level;
        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}

/* =================================================
   5. Maximum Depth (Height of Tree)
   ================================================= */
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

/* =================================================
   6. Check if Tree is Height Balanced
   ================================================= */
int checkHeight(TreeNode* root) {
    if (!root) return 0;
    int lh = checkHeight(root->left);
    if (lh == -1) return -1;
    int rh = checkHeight(root->right);
    if (rh == -1) return -1;
    if (abs(lh - rh) > 1) return -1;
    return 1 + max(lh, rh);
}

bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}

/* =================================================
   7. Diameter of Binary Tree
   ================================================= */
int diameterUtil(TreeNode* root, int& dia) {
    if (!root) return 0;
    int lh = diameterUtil(root->left, dia);
    int rh = diameterUtil(root->right, dia);
    dia = max(dia, lh + rh);
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode* root) {
    int dia = 0;
    diameterUtil(root, dia);
    return dia;
}

/* =================================================
   8. Maximum Path Sum
   ================================================= */
int maxPathUtil(TreeNode* root, int& maxi) {
    if (!root) return 0;
    int l = max(0, maxPathUtil(root->left, maxi));
    int r = max(0, maxPathUtil(root->right, maxi));
    maxi = max(maxi, root->val + l + r);
    return root->val + max(l, r);
}

int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    maxPathUtil(root, maxi);
    return maxi;
}

/* =================================================
   9. Check if Two Trees are Identical
   ================================================= */
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return (p->val == q->val &&
            isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right));
}

/* =================================================
   10. Zigzag Level Order Traversal
   ================================================= */
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int sz = q.size();
        vector<int> level(sz);
        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front(); q.pop();
            int idx = leftToRight ? i : sz - i - 1;
            level[idx] = node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        leftToRight = !leftToRight;
        ans.push_back(level);
    }
    return ans;
}

/* =================================================
   11. Boundary Traversal
   ================================================= */
bool isLeaf(TreeNode* node) {
    return node && !node->left && !node->right;
}

void addLeft(TreeNode* root, vector<int>& res) {
    TreeNode* cur = root->left;
    while (cur) {
        if (!isLeaf(cur)) res.push_back(cur->val);
        cur = cur->left ? cur->left : cur->right;
    }
}

void addLeaves(TreeNode* root, vector<int>& res) {
    if (isLeaf(root)) {
        res.push_back(root->val);
        return;
    }
    if (root->left) addLeaves(root->left, res);
    if (root->right) addLeaves(root->right, res);
}

void addRight(TreeNode* root, vector<int>& res) {
    vector<int> temp;
    TreeNode* cur = root->right;
    while (cur) {
        if (!isLeaf(cur)) temp.push_back(cur->val);
        cur = cur->right ? cur->right : cur->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
        res.push_back(temp[i]);
}

vector<int> boundaryTraversal(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    if (!isLeaf(root)) res.push_back(root->val);
    addLeft(root, res);
    addLeaves(root, res);
    addRight(root, res);
    return res;
}

/* =================================================
   12. Vertical Order Traversal
   ================================================= */
vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> mp;
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty()) {
        auto p = q.front(); q.pop();
        TreeNode* node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        mp[x][y].insert(node->val);

        if (node->left)
            q.push({node->left, {x - 1, y + 1}});
        if (node->right)
            q.push({node->right, {x + 1, y + 1}});
    }

    vector<vector<int>> ans;
    for (auto& col : mp) {
        vector<int> temp;
        for (auto& row : col.second) {
            temp.insert(temp.end(), row.second.begin(), row.second.end());
        }
        ans.push_back(temp);
    }
    return ans;
}

/* =================================================
   13. Lowest Common Ancestor (LCA)
   ================================================= */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q)
        return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (!left) return right;
    if (!right) return left;
    return root;
}

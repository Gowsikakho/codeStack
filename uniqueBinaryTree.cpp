#include <bits/stdc++.h>
using namespace std;

// ---------------- Tree Node ----------------
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

// ---------------- Solution Class ----------------
class Solution {
public:
    unordered_map<int, int> inMap;

    // ===== 1. Build from PREORDER + INORDER =====
    int preIdx;

    TreeNode* buildPreIn(int st, int end, vector<int>& preorder) {
        if (st > end) return nullptr;

        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        int idx = inMap[rootVal];

        root->left  = buildPreIn(st, idx - 1, preorder);
        root->right = buildPreIn(idx + 1, end, preorder);

        return root;
    }

    TreeNode* buildTreeFromPreIn(vector<int>& preorder, vector<int>& inorder) {
        inMap.clear();
        preIdx = 0;

        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;

        return buildPreIn(0, inorder.size() - 1, preorder);
    }

    // ===== 2. Build from POSTORDER + INORDER =====
    int postIdx;

    TreeNode* buildPostIn(int st, int end, vector<int>& postorder) {
        if (st > end) return nullptr;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int idx = inMap[rootVal];

        // build RIGHT first
        root->right = buildPostIn(idx + 1, end, postorder);
        root->left  = buildPostIn(st, idx - 1, postorder);

        return root;
    }

    TreeNode* buildTreeFromPostIn(vector<int>& postorder, vector<int>& inorder) {
        inMap.clear();
        postIdx = postorder.size() - 1;

        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;

        return buildPostIn(0, inorder.size() - 1, postorder);
    }
};

// ---------------- Traversal Helpers ----------------
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printPostorder(TreeNode* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

// ---------------- Main ----------------
int main() {
    Solution sol;

    vector<int> inorder   = {9, 3, 15, 20, 7};
    vector<int> preorder  = {3, 9, 20, 15, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    // Build using Preorder + Inorder
    TreeNode* root1 = sol.buildTreeFromPreIn(preorder, inorder);
    cout << "Inorder (from Pre+In): ";
    printInorder(root1);
    cout << "\n";

    // Build using Postorder + Inorder
    TreeNode* root2 = sol.buildTreeFromPostIn(postorder, inorder);
    cout << "Postorder (from Post+In): ";
    printPostorder(root2);
    cout << "\n";

    return 0;
}

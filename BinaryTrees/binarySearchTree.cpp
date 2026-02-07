#include <bits/stdc++.h>
using namespace std;

/* =========================
   BST Node Definition
   ========================= */
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* =========================
   1. Search in BST
   Time: O(h)
   ========================= */
TreeNode* searchBST(TreeNode* root, int key) {
    if (!root || root->val == key) return root;
    if (key < root->val) return searchBST(root->left, key);
    return searchBST(root->right, key);
}

/* =========================
   2. Insert into BST
   ========================= */
TreeNode* insertBST(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->val)
        root->left = insertBST(root->left, key);
    else
        root->right = insertBST(root->right, key);
    return root;
}

/* =========================
   3. Find Minimum in BST
   ========================= */
TreeNode* findMin(TreeNode* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

/* =========================
   4. Delete a Node in BST
   ========================= */
TreeNode* deleteBST(TreeNode* root, int key) {
    if (!root) return NULL;

    if (key < root->val)
        root->left = deleteBST(root->left, key);
    else if (key > root->val)
        root->right = deleteBST(root->right, key);
    else {
        // Case 1 & 2
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        TreeNode* succ = findMin(root->right);
        root->val = succ->val;
        root->right = deleteBST(root->right, succ->val);
    }
    return root;
}

/* =========================
   5. Validate BST
   ========================= */
bool isValidBST(TreeNode* root, long minVal, long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal)
        return false;
    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
}

/* =========================
   6. LCA in BST
   ========================= */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return NULL;

    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);

    return root;
}

/* =========================
   7. Kth Smallest in BST
   ========================= */
void inorderK(TreeNode* root, int& k, int& ans) {
    if (!root) return;
    inorderK(root->left, k, ans);
    if (--k == 0) {
        ans = root->val;
        return;
    }
    inorderK(root->right, k, ans);
}

int kthSmallest(TreeNode* root, int k) {
    int ans = -1;
    inorderK(root, k, ans);
    return ans;
}

/* =========================
   8. Floor in BST
   ========================= */
int floorBST(TreeNode* root, int key) {
    int ans = -1;
    while (root) {
        if (root->val == key)
            return root->val;
        if (root->val < key) {
            ans = root->val;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return ans;
}

/* =========================
   9. Ceil in BST
   ========================= */
int ceilBST(TreeNode* root, int key) {
    int ans = -1;
    while (root) {
        if (root->val == key)
            return root->val;
        if (root->val > key) {
            ans = root->val;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ans;
}

/* =========================
   10. Recover BST (2 swapped nodes)
   ========================= */
TreeNode *first = NULL, *middle = NULL, *last = NULL, *prevNode = NULL;

void inorderRecover(TreeNode* root) {
    if (!root) return;

    inorderRecover(root->left);

    if (prevNode && root->val < prevNode->val) {
        if (!first) {
            first = prevNode;
            middle = root;
        } else {
            last = root;
        }
    }
    prevNode = root;

    inorderRecover(root->right);
}

void recoverBST(TreeNode* root) {
    inorderRecover(root);
    if (first && last)
        swap(first->val, last->val);
    else if (first && middle)
        swap(first->val, middle->val);
}

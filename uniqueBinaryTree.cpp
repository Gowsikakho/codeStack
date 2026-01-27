#include <bits/stdc++.h>
using namespace std;

// Tree node definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    unordered_map<int, int> inorderIndex;
    int preIdx = 0;

    TreeNode* build(int start, int end, vector<int>& preorder) {
        // no elements to build
        if (start > end) return nullptr;

        // current root from preorder
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        // find root in inorder
        int idx = inorderIndex[rootVal];

        // build left then right
        root->left  = build(start, idx - 1, preorder);
        root->right = build(idx + 1, end, preorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

        // store inorder value -> index
        for (int i = 0; i < n; i++)
            inorderIndex[inorder[i]] = i;

        return build(0, n - 1, preorder);
    }
};

// Helper: print inorder (to verify)
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Main function
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder  = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Inorder traversal of constructed tree:\n";
    printInorder(root);

    return 0;
}

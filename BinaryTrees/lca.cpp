#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Function to find LCA in Binary Tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    // Base case
    if (root == nullptr)
        return nullptr;

    // If root is one of the nodes
    if (root == p || root == q)
        return root;

    // Recur on left and right subtree
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both sides return non-null, root is LCA
    if (left != nullptr && right != nullptr)
        return root;

    // Otherwise return the non-null value
    return (left != nullptr) ? left : right;
}

// Driver code
int main() {

    /*
            3
           / \
          5   1
         / \ / \
        6  2 0  8
          / \
         7   4
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Nodes for which LCA is to be found
    TreeNode* p = root->left;                   // Node 5
    TreeNode* q = root->left->right->right;     // Node 4

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != nullptr)
        cout << "LCA = " << lca->val << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}

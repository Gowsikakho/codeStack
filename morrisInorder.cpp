#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void morrisInorder(TreeNode* root) {
    TreeNode* curr = root;

    while (curr != nullptr) {
        // Case 1: No left child
        if (curr->left == nullptr) {
            cout << curr->val << " ";
            curr = curr->right;
        }
        // Case 2: Has left child
        else {
            TreeNode* pred = curr->left;

            // Find inorder predecessor
            while (pred->right != nullptr && pred->right != curr) {
                pred = pred->right;
            }

            // Create temporary thread
            if (pred->right == nullptr) {
                pred->right = curr;
                curr = curr->left;
            }
            // Remove temporary thread
            else {
                pred->right = nullptr;
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
}

int main() {
    /*
            1
             \
              2
             /
            3

        Inorder traversal: 1 3 2
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    cout << "Morris Inorder Traversal: ";
    morrisInorder(root);
    cout << endl;

    return 0;
}

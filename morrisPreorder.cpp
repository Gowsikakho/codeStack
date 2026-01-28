#include <bits/stdc++.h>
using namespace std;

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

void morrisPreorder(TreeNode* root) {
    TreeNode* cur = root;

    while (cur != nullptr) {
        if (cur->left == nullptr) {
            cout << cur->val << " ";
            cur = cur->right;
        } else {
            TreeNode* pred = cur->left;

            while (pred->right != nullptr && pred->right != cur) {
                pred = pred->right;
            }

            if (pred->right == nullptr) {
                // first visit (PREORDER visit here)
                cout << cur->val << " ";
                pred->right = cur;
                cur = cur->left;
            } else {
                // second visit
                pred->right = nullptr;
                cur = cur->right;
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

        Preorder: 1 2 3
    */

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    cout << "Morris Preorder Traversal: ";
    morrisPreorder(root);
    cout << "\n";

    return 0;
}

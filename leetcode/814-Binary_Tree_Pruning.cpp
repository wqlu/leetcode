#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return root;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->val == 1 || root->left || root->right) {
            return root;
        }
        delete root;
        return nullptr;
    }
};

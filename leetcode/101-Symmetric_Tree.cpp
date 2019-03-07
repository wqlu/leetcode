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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        if ((root ->left == NULL && root->right != NULL) || (root ->left != NULL && root->right == NULL)) {
            return false;
        } else {
            return isSame(root->left, root->right);
        }
    }

    bool isSame(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) {
            return true;
        } else if (left != NULL && right != NULL){
            return (left->val == right->val) && isSame(left->left, right->right) && isSame(left->right, right->left);
        } else {
            return false;
        }
    }
};
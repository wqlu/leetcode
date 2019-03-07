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
    bool isUnivalTree(TreeNode* root) {
        node_value = root->val;
        return preorder(root, node_value);

    }

    bool preorder(TreeNode*& root, const int& value) {
        if (root != nullptr) {
            if (root->val != value) {
                return false;
            }
            return (preorder(root->left, value) && preorder(root->right, value));
        }
        return true;
    }

private:
    int node_value;
};
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if (pRoot == NULL) {
            return true;
        }  
        return comRoot(pRoot->left, pRoot->right);
    }

    bool comRoot(TreeNode* left, TreeNode* right) {
        if (left == NULL)
            return right == NULL;
        if (right == NULL)
            return false;
        if (left->val != right->val)
            return false;
        return comRoot(left->right, right->left) && comRoot(left->left, right->right);
    }
};

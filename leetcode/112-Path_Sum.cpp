class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right && sum == root->val)
            return true;
        int tmp = sum - root->val;
        if (hasPathSum(root->left, tmp) || hasPathSum(root->right, tmp))
            return true;
        return false;
    }
};
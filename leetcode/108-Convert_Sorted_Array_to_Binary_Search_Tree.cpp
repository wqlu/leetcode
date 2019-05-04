class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = toBST(nums, 0, nums.size() - 1);
        return root;
    }

    TreeNode* toBST(vector<int>& nums, int begin, int end) {
        if (end < begin) return nullptr;
        int pos = begin + (end - begin) / 2;
        TreeNode* root = new TreeNode(nums[pos]);
        root->left = toBST(nums, begin, pos - 1);
        root->right = toBST(nums, pos + 1, end);
        return root;
    }
};
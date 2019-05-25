class Solution {
public:
     bool findTarget(TreeNode *root, int k) {
		vector<int> nums;
		MidOrder(root, nums);
		int low = 0, high = nums.size() - 1;
		while (low < high) {
			if (k == nums[low] + nums[high]) {
				return true;
			} else if (k < nums[low] + nums[high]) {
				high--;
			} else {
				low++;
			}
		}
		return false;
	}
	
	void MidOrder(TreeNode *root, vector<int> &nums) {
		if (!root) return;
		MidOrder(root->left, nums);
		nums.push_back(root->val);
		MidOrder(root->right, nums);
	}
};
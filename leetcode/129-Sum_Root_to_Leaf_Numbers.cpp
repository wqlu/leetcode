/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
		if (!root) return 0;
		ans = 0;
		DFS(root, 0);
		return ans;
	}

	void DFS(TreeNode* root, int val) {
		if (!root) return;
        int cur_num = val * 10 + root->val;
		if (!root->left && !root->right) {
			ans += cur_num;
		} else {
			DFS(root->left, cur_num);
			DFS(root->right, cur_num);
		}
	}
private:
	int ans;
};
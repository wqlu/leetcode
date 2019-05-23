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
    TreeNode *bstFromPreorder(vector<int> &preorder) {
		TreeNode *root = bstFromPreorderIndex(preorder, 0, preorder.size() - 1);
		return root;
	}

	TreeNode *bstFromPreorderIndex(vector<int> &preorder, int begin, int end) {
		if (begin > end) {
			return nullptr;
		} else if (begin == end) {
			TreeNode *root = new TreeNode(preorder[begin]);
			return root;
		} else {
			int index = end + 1;
			for (int i = begin; i <= end; ++i) {
				if (preorder[i] > preorder[begin]) {
					index = i;
					break;
				}
			}
			TreeNode *root = new TreeNode(preorder[begin]);
			root->left = bstFromPreorderIndex(preorder, begin + 1, index-1);
			root->right = bstFromPreorderIndex(preorder, index, end);
			return root;
		}
	}
};
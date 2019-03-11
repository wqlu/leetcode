#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return {};
        vector<TreeNode*> curr, next;
        curr.push_back(root);
        while(!curr.empty()){
            ans.push_back({});
            for (TreeNode* node : curr) {
                ans.back().push_back(node->val);
                if (node->left) next.push_back(node->left);
                if (node->right) next.push_back(node->right);
            }
            curr.swap(next);
            next.clear();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        // DFS(root, 0, ans);
        if (!root) return {};
        vector<TreeNode*> curr, next;
        curr.push_back(root);
        while (!curr.empty()) {
            ans.push_back({});
            for (TreeNode* node : curr) {
                ans.back().push_back(node->val);
                if (node->left) next.push_back(node->left);
                if (node->right) next.push_back(node->right);
            }
            swap(curr, next);
            next.clear();
        } 
        return ans;
    }
private:
    // 法二：
    void DFS(TreeNode* root, int depth, vector<vector<int>>& ans) {
        if (!root) return;
        while (ans.size() <= depth) ans.push_back({});
        ans[depth].push_back(root->val);
        DFS(root->left, depth + 1, ans);
        DFS(root->right, depth + 1, ans);
    }
};
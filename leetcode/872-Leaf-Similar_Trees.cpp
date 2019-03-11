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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> root1_leaves, root2_leaves;
        getLeaves(root1, root1_leaves);
        getLeaves(root2, root1_leaves);
        if (root1_leaves.empty() || root2_leaves.empty()) {
            return false;
        }
        if (root1_leaves.size() != root2_leaves.size()) {
            return false;
        } else {
            // sort(root1_leaves.begin(), root1_leaves.end());
            // sort(root2_leaves.begin(), root2_leaves.end());
            for (int i = 0; i < root1_leaves.size(); i++) {
                if (root1_leaves[i] != root2_leaves[i]) {
                    return false;
                }
            }
            return true;
        }
    }
private:
    void getLeaves(TreeNode* root, vector<int>& leaves) {
        if (!root) { 
            return;
        } else {
            if (!root->left && !root->right) {
                leaves.push_back(root->val);
            }
            getLeaves(root->left, leaves);
            getLeaves(root->right, leaves);
        }
    }
};
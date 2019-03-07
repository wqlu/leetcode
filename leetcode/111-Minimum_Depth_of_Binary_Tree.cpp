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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int ans = 1;
        ans = travelsal(root, ans);
        return ans;
    }

    int travelsal(TreeNode*& root, int& ans) {
        if (root->left || root->right) {
            return ans;
        } else {
            ans += 1;
            ans = min(travelsal(root->left, ans), travelsal(root->right, ans));
        }
        return ans;
    }
};
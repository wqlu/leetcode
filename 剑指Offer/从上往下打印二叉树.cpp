#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode* > queue1;
        vector<int> ans;
        TreeNode* temp;
        if (root)
            queue1.push(root);
        else
            return ans;
        while (!queue1.empty()) {
            temp = queue1.front();
            queue1.pop();
            ans.push_back(temp->val);
            if (temp->left)
                queue1.push(temp->left);
            if (temp->right)
                queue1.push(temp->right);
        }
        return ans;
    }
};
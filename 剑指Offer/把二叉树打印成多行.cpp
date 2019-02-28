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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > ans;
        vector<int> row;
        int count = 0, row_size = 1; // count 用来计算下一行的个数， row_size 每一行的个数
        queue<TreeNode *> temp;
        if (pRoot) {
            temp.push(pRoot);
        } else {
            return ans;
        }
        while (!temp.empty()) {
            TreeNode * front_Node = temp.front();
            if (front_Node->left) {
                temp.push(front_Node->left);
                count += 1;
            }
            if (front_Node->right) {
                temp.push(front_Node->right);
                count += 1;
            }
            if (row_size > 0) {
                row.push_back(front_Node->val);
                row_size -= 1;
            } 
            if (row_size == 0) {
                ans.push_back(row);
                row.clear();
                row_size = count;
                count = 0;
            }
            temp.pop();
        }
        return ans;
    }
};

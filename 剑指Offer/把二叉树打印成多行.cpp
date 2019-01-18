#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (pRoot == NULL) {
            return res;
        }
        queue<TreeNode*> que;
        while (!que.Empty()) {
            vector<int> temp;
            const int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = que.front();
                
            }
        }
    }
};

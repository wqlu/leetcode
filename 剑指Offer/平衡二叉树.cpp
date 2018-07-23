//
// Created by lu on 18-7-23.
// Email: wq.lu@outlook.com
//

#include <iostream>
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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot == NULL)
            return true;
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        if (abs(left-right) < 1 && IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right))
            return true;
        return false;
    }

    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == NULL)
            return 0;
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        int ans = (left > right) ? (left + 1) : (right + 1);
        return ans;
    }
};
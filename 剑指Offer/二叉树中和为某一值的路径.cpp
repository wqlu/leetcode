#include <iostream>
#include <vector>
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
    vector<vector<int> > allRes;
    vector<int> tmp;
    void dfsFind(TreeNode *node, int left) {
        tmp.push_back(node->val);
        if (left - node->val == 0 && !node->left && !node->right)
            allRes.push_back(tmp);
        else {
            if (node->left) 
                dfsFind(node->left, left - node->val);
            if (node->right)
                dfsFind(node->right, left - node->val);
        }
        // 深度遍历是要回退的
        tmp.pop_back(); 
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root) 
            dfsFind(root, expectNumber);
        return allRes;
    }
};

int main(void)
{
  return 0;
}

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(ans, root);
        return ans;
    }

    void inorder(vector<int>& ans, TreeNode* &root) {
        stack<TreeNode*> s; 
        while (root != NULL || !s.empty()) {
            if (root != NULL) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                ans.push_back(root->val);
                s.pop();
                root = root->right;
            }
        }
    }

    void preorder(vector<int>& ans, TreeNode* & root) {
        stack<TreeNode* > s;
        while (root != NULL || !s.empty()) {
            if (root != NULL) {
                ans.push_back(root->val);
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                root = root->right;
            }
        }
    }

    void postorder(vector<int>& ans, TreeNode* & root) {
        
    }
};

/**
 * 前序遍历 [1, 2, 4, 5, 3, 6, 7]
 * 中序遍历 [4, 2, 5, 1, 6, 3, 7]
 * 后序遍历 [4, 5, 2, 6, 7, 3, 1]
 */

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode (3);
    TreeNode *l1 = root->left;
    TreeNode *l2 = root->right;
    l1->left = new TreeNode(4);
    l1->right = new TreeNode(5);
    l2->left = new TreeNode(6);
    l2->right = new TreeNode(7);
    Solution s;
    vector<int> ans = s.inorderTraversal(root);
    cout << "[ ";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "]" << endl;
    return 0;
}
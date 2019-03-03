#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        n_preorder(ans, root);
        return ans;
    }

    void n_preorder(vector<int>& ans, Node* & root) {
        if (root) {
            ans.push_back(root->val);
            for (Node * n : root->children) {
                n_preorder(ans, n);
            }
        }
    }
};
#include <iostream>
#include <vector>

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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        n_postorder(ans, root);
        return ans;
    }

    void n_postorder(vector<int>& ans, Node* root) {
        if (root != NULL) {
            if (root->children.size() == 0) {
                ans.push_back(root->val);
            } else {
                for (Node* child : root->children) {
                    n_postorder(ans, child);
                }
                ans.push_back(root->val);
            }
        } else {
            return;
        }
    }
};
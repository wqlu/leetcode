#include <iostream>
#include <vector>

using namespace std;

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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (!root) return {};
        vector<Node*> curr, next;
        curr.push_back(root);
        while (!curr.empty()) {
            ans.push_back({});
            for (Node* node : curr) {
                ans.back().push_back(node->val);
                for (Node* child : node->children) {
                    next.push_back(child);
                }
            }
            curr.swap(next);
            next.clear();
        }
        return ans;
    }
};
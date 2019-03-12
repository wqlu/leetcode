#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};
        map<pair<int, int>, set<int>> node_map;
        vector<vector<int>> ans;
        traversal(root, 0, 0, node_map);
        for (const auto& node : node_map) {
            int x = node.first.second;
            
        }
    }
private:
    void traversal(TreeNode*& root,int x_coordinate, int y_coordinate, map<pair<int, int>, set<int>>& node_map) {
        if (!root) return;
        node_map[{y_coordinate, x_coordinate}].insert(root->val);
        traversal(root->left, x_coordinate - 1, y_coordinate + 1, node_map);
        traversal(root->right, x_coordinate - 1, y_coordinate + 1, node_map);
    }
};

int main() {
    return 0;
}
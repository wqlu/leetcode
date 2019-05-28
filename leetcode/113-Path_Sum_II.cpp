class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<int> tmp;
        DFS_2(root, tmp, sum);
        return ret;
    }

    void DFS_2(TreeNode *root, vector<int> tmp,  int sum) {
        if (!root ) return;
        // 是否叶子节点
        if (!root->left && !root->right) {
            if (root->val == sum) {
                tmp.push_back(root->val);
                ret.push_back(tmp);
            } 
        } else {
            tmp.push_back(root->val);
            DFS_2(root->left, tmp, sum - root->val);
            DFS_2(root->right, tmp, sum - root->val);
        }
        return;
    }

private:
    vector<vector<int>> ret;
};
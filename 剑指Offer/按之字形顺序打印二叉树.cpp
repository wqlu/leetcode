class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (pRoot == NULL) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(pRoot);
        bool even = false;
        while (!que.empty()) {
            vector<int> vec;
            const int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = que.front();
                que.pop();
                vec.push_back(temp->val);
                if (temp->left != NULL) {
                    que.push(temp->left);
                }
                if (temp->right != NULL) {
                    que.push(temp->right);
                }
            }
            if (even) {
                std::reverse(vec.begin(), vec.end());
            }
            res.push_back(vec);
            even = !even;
        }
        return res;
    }   
};

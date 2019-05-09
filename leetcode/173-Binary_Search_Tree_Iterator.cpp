/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        mid(root);
        index = 0;
    }
    
    void mid(TreeNode* root) {
        if (!root) return;
        
        mid(root->left);
        nodes.push_back(root->val);
        mid(root->right);
    
        return;
    } 
    
    /** @return the next smallest number */
    int next() {
        int val = nodes[index];
        index++;
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (index < nodes.size())
            return true;
        return false;
    }
private:
    vector<int> nodes;
    int index;
};


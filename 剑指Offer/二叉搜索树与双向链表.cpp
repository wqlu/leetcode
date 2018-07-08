
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode *pLastNodeInList = NULL;
        ConvertNode(pRootOfTree, &pLastNodeInList);
    }

    void ConvertNode(TreeNode *pNode, TreeNode  **pLastNodeInList) {
        if (pNode == NULL)
            return;
        TreeNode *pCurrent = pNode;
        
        if (pCurrent->left != NULL)
            ConvertNode(pCurrent->left, pLastNodeInList);

        
    }
};

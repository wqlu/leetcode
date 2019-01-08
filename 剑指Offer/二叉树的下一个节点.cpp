struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL) {}
};


/**
 * 链接：https://www.nowcoder.com/questionTerminal/9023a0c988684a53960365b889ceaf5e
来源：牛客网
1.二叉树为空，则返回空；
2.节点右孩子存在，则设置一个指针从该节点的右孩子出发，一直沿着指向左子结点的指针找到的叶子节点即为下一个节点；
3.节点不是根节点。如果该节点是其父节点的左孩子，则返回父节点；否则继续向上遍历其父节点的父节点，重复之前的判断，返回结果。代码如下：
 */
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (pNode == NULL) {
            return NULL;
        }
        if (pNode->right != NULL) {
            pNode = pNode->right;
            while (pNode->left != NULL) {
                pNode = pNode->left;
            }
            return pNode;
        }
        while (pNode->next != NULL) {
            TreeLinkNode *proot = pNode->next;
            if (proot->left == pNode) {
                return proot;
            }
            pNode = pNode->next;
        }
        return NULL;
    }
};
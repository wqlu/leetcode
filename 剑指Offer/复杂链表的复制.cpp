struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
     RandomListNode* Clone(RandomListNode *pHead) {
        if (pHead == NULL)
            return NULL;

        // 开辟一个新节点
        RandomListNode *pClonedHead = new RandomListNode(pHead->label);
        pClonedHead->next = pHead->next;
        pClonedHead->random = pHead->random;

        // 递归其他节点
        pClonedHead->next = Clone(pHead->next);
        return pClonedHead;
     }        
};

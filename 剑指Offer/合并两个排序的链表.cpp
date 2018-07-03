struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* pMerge = NULL; // 新合成的头节点
        ListNode* pNode = NULL; // 新合成的当前节点

        if (pHead1 == NULL)
            return pHead2;
        else if (pHead2 == NULL)
            return pHead1;
        else {
            if (pHead1->val > pHead2->val) {
                pMerge = pHead2;
                pHead2 = pHead2->next;
            } else {
                pMerge = pHead1;
                pHead1 = pHead1->next;
            }
            pNode = pMerge;
            pNode->next = NULL;
        }

        while (pHead1 != NULL && pHead2 != NULL) {
            if (pHead1->val > pHead2->val) {
                pNode->next = pHead2;
                pNode = pHead2;
                pHead2 = pHead2->next;
            } else {
                pNode->next = pHead1;
                pNode = pHead1;
                pHead1 = pHead1->next;
            }
            pNode->next = NULL;
        }
        if (pHead1 != NULL)
            pNode->next = pHead1;
        if (pHead2 != NULL)
            pNode->next = pHead2;
        return pMerge;
    }
};

// 递归版本
class Solution2 {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL)
            return pHead2;
        if (pHead2 == NULL)
            return pHead1;

        ListNode* newhead = NULL;

        if (pHead1->val < pHead2->val) {
            newhead = pHead1;
            newhead->next = Merge(pHead1->next, pHead2);
        } else {
            newhead = pHead2;
            newhead->next = Merge(pHead1, pHead2->next);
        }
        return newhead;
    }
};

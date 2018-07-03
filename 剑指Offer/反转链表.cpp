#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
	    if (pHead == NULL)
	        return NULL;

	    ListNode* pNode = pHead; // 当前pointer
        ListNode* pReverseHead = NULL; // 新链表的头
        ListNode* pPrev = NULL; // 当前pointer的前一个

        while (pNode != NULL) {
            ListNode* pNext = pNode->next;

            if (pNext == NULL)
                pReverseHead = pNode;

            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pReverseHead;
	}
};

int main() {
	return 0;
}

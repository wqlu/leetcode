#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} 
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if (pHead == NULL || pHead->next == NULL) {
            return pHead;
        }
        int temp_data = pHead->val;
        ListNode* result = pHead;
        while (pHead->next != NULL) {
            if (pHead->nex->val == temp_data) {
                // delete pHead->next note
                ListNode* temp = pHead->next->next;
                pHead->next = temp;
            } else {
                pHead = pHead->next;
                temp_data = pHead->val;
            }
        }
        return result;
    }
};

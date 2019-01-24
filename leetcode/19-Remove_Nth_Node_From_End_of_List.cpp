/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *front = head, *back = head;
        for (int i = 0; i < n; ++i) {
            back = back->next;
        }
        if (back == NULL) {
            return front->next;
        }
        while (back->next) {
            front = front->next;
            back = back->next;
        }
        ListNode* tmp = front->next->next;
        front->next = tmp;
        return head;
    }
};
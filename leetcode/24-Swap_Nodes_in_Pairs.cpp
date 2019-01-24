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
    ListNode* swapPairs(ListNode* head) {
        if (!head) 
            return NULL;
        ListNode* ans = head;
        while (head->next != NULL) {
            swap(head->val, head->next->val);
            if (head->next->next == NULL) {
                head = head->next;
            } else {
                head = head->next->next;
            }
        }
        return ans;
    }
};
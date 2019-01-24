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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans;
        if (!l1 && !l2)
            return NULL;
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val <= l2->val) {
            ans = l1;
            l1 = l1->next;
        } else {
            ans = l2;
            l2 = l2->next;
        }
        ListNode *tmp = ans;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tmp->next = l1;
                tmp = l1;
                l1 = l1->next;
            } else {
                tmp->next = l2;
                tmp = l2;
                l2 = l2->next;
            }
        }
        while (l1) {
            tmp->next = l1;
            tmp = l1;
            l1 = l1->next;
        }
        while (l2) {
            tmp->next = l2;
            tmp = l2;
            l2 = l2->next;
        }
        return ans;
    }
};
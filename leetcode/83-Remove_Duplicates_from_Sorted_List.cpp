
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        int tmp = head->val;
        ListNode* root = head, *pre = head;
        head = head->next;
        while (head) {
            if (head->val == tmp) {
                pre->next = head->next;
                head = head->next;
            } else {
                tmp = head->val;
                pre = pre->next;
            }
        }
        return root;
    }
};
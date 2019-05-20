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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return NULL;
        ListNode *pre = head, *curr = head->next, *root = head;
        while (curr) {
            // 遍历所有节点
            int tmp = curr->val;
            if (tmp >= pre->val) { // 如果大于的话，继续前进
                pre = pre->next;
                curr= curr->next;
            } else {
                pre->next = curr->next;
                curr = curr->next;
                // 找到合适的位置插入
                if (tmp < root->val) { // 如果是最小的
                    ListNode* insert_tmp = new ListNode(tmp);
                    insert_tmp->next = root;
                    root = insert_tmp;
                } else {
                    ListNode * insert_curr = root->next, *insert_pre = root;
                    while (insert_curr) {
                        if (tmp < insert_curr->val) {
                            ListNode* insert_tmp = new ListNode(tmp);
                            insert_pre->next = insert_tmp;
                            insert_tmp->next = insert_curr;
                            break;
                        }
                        insert_curr = insert_curr->next;
                        insert_pre = insert_pre->next;
                    }
                }
            }
        }
        return root;
    }
};
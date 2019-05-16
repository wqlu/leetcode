#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       stack<int> s1, s2;
       while (l1) {
           s1.push(l1->val);
           l1 = l1->next;
       } 
       while (l2) {
           s2.push(l2->val);
           l2 = l2->next;
       }
       ListNode* head = nullptr;
       int sum = 0;
       while (!s1.empty() || !s2.empty() || sum) {
           sum += s1.empty() ? 0 : s1.top();
           sum += s2.empty() ? 0 : s2.top();
           if (!s1.empty()) s1.pop();
           if (!s2.empty()) s2.pop();
           ListNode* n = new ListNode(sum % 10);
           sum /= 10;
           n->next = head;
           head = n;
       }
       return head;
    }

    int getValue(ListNode* l) {
        int ans = 0;
        while (l != nullptr) {
            ans = (ans * 10 ) +  l->val;
            l = l->next;
        }
        return ans;
    }

    ListNode* getList(int value) {
        int node_value;
        ListNode* back = nullptr, *root = nullptr;
        while (value != 0) {
            node_value = value % 10;
            value /= 10;
            root = new ListNode(node_value);
            root->next = back;
            back = root;
        }
        return root;
    }
};
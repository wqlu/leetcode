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
    ListNode* reverseList(ListNode* head) {
        stack<int> s;
        while (head) {
            s.push(head->val);
            head = head->next;
        }
        ListNode* root = nullptr, *cur = nullptr; 
        if (!s.empty()) {
            root = new ListNode(s.top());
            cur = root;
            s.pop();
        }
        while (!s.empty()) {
            ListNode* node = new ListNode(s.top());
            s.pop();
            cur->next = node;
            node->next = nullptr;
            cur = node;
            
        }
        return root;
    }
};
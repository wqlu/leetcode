#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode *curr1 = head, *curr2 = head;
        vector<int> v;
        while (curr1 != NULL) {
            v.push_back(curr1->val);
            curr1 = curr1->next;
        }
        sort(v.begin(), v.end());
        int index = 0;
        while (curr2 != NULL) {
            curr2->val = v[index++];
            curr2 = curr2->next;
        }
        return head;
    }
};
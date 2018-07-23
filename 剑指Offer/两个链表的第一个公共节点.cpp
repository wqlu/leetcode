//
// Created by lu on 18-7-23.
//
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
        int num_p1 = 0, num_p2 = 0;
        ListNode *temp_1 = pHead1, *temp_2 = pHead2;
        while (temp_1 != NULL) {
            num_p1++;
            temp_1 = temp_1->next;
        }
        while (temp_2 != NULL) {
            num_p2++;
            temp_2 = temp_2->next;
        }
        int distance = (num_p1 > num_p2) ? (num_p1-num_p2) : (num_p2 - num_p1);
        ListNode *ans = NULL;
        if (num_p1 > num_p2) {
            while (distance > 0) {
                pHead1 = pHead1->next;
                distance--;
            }
        } else {
            while (distance > 0) {
                pHead2 = pHead2->next;
                distance--;
            }
        }
        while (pHead1 != NULL && pHead2 != NULL) {
            if (pHead1 == pHead2) {
                ans = pHead1;
                break;
            }
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return ans;
    }
};
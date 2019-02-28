#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        set<int> temp;
        bool ans = false;
        set<int>::iterator it;
        if (length <= 1) {
            return ans;
        }
        for (int i = 0; i < length; ++i) {
            it = temp.find(numbers[i]);
            if (it == temp.end()) {
                temp.insert(numbers[i]);
            } else {
                *duplication = numbers[i];
                ans = true;
                break;
            }
        } 
        return ans;
    }
};
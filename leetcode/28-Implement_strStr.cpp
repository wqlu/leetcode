#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        int ans = -1;
        const int haystack_len = haystack.size();
        const int needle_len = needle.size();
        for (int i = 0; i <= haystack_len - needle_len; ++i) {
            bool flag = true;
            for (int j = 0; j < needle_len; ++j) {
                if (haystack[i+j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
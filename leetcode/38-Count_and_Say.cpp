#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ans = "";
        if (n == 1) {
            ans = "1";
        } else {
            string pre_ans = countAndSay(n-1);
            const int pre_ans_size = pre_ans.size();
            char curr = pre_ans[0];
            int curr_count = 1;
            for (int i = 1; i < pre_ans_size; ++i) {
                if (pre_ans[i] == curr) {
                    curr_count += 1;
                    continue;
                } else {
                    for (int j = 0; j < curr_count; ++j) {
                        ans = ans + to_string(curr_count) + curr;
                    }
                    if (i + 1 < pre_ans_size) {
                        
                    }
                }
            }
        }
    }
};
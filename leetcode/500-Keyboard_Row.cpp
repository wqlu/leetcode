#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string> &words) {
        unordered_map<int, string> keyboard({{0,"QWERTYUIOP"}, {1,"ASDFGHJKL"}, {2,"ZXCVBNM"}});
        for (const auto &s : words) {
            for (auto & c : s) {
                
            }
        }
    }
};

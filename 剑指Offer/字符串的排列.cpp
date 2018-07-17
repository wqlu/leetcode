#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
     vector<string> Permutation(string str) {
        set<char> set_char;
        vector<string> vector_ans;
        for (int i = 0; i < str.size(); i++) {
            set_char.insert(str[i]); 
        }
}; 

int main() {
    Solution solution;
    string str = "abc";
    solution.Permutation(str);
    return 0;
}

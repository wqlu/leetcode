
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        multiset<int, greater<int>> ans;
        vector<int> final_ans;
        if (k >= input.size())
            return final_ans;

        vector<int>::const_iterator iter = input.begin();
        for (; iter != input.end(); ++iter) {
            if (ans.size() < k)
                ans.insert(*iter);
            else {
                multiset<int>::iterator iterator1 = ans.begin();
                if (*iter < *(ans.begin())) {
                    ans.erase(iterator1);
                    ans.insert(*iter);
                }
            }
        }
        for (auto i : ans) {
            final_ans.push_back(i);
        }
        return final_ans;
    }
};

int main() {

    vector<int> vector1;
    vector1.push_back(4);
    vector1.push_back(5);
    vector1.push_back(1);
    vector1.push_back(6);
    vector1.push_back(2);
    vector1.push_back(7);
    vector1.push_back(3);
    vector1.push_back(8);
    Solution solution;
    vector<int> ans;
    ans = solution.GetLeastNumbers_Solution(vector1, 4);
    for(int i : ans) {
        cout << i << endl;
    }
    return 0;
}
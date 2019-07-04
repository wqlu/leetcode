#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;

        int h = 0;
        while ((label >> (h + 1)) > 0) h++;

        ans.push_back(label);

        while(h > 0){
            int pos = ((1 << (h + 1)) - 1 - label) >> 1;
            label = (1 << (h - 1)) + pos;
            h--;
            ans.push_back(label);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {

    Solution s;
    vector<int> ans = s.pathInZigZagTree(14);
    return 0;
}

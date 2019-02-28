#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        findAns(ans, candidates, target);
        return ans;
    }

    void findAns(vector<vector<int> >&ans, vector<int>& candidates, int target) {
        
    }

};
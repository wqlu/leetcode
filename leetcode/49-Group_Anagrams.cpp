#include <iostream>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map_ans;
        const int strs_size = strs.size();
        for (int i = 0; i < strs_size; ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            map_ans[tmp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (const auto& it : map_ans){
            ans.push_back(it.second);
        }
        return ans;
    }
};
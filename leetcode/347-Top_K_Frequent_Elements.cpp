class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> p;
        for (const auto &it : nums) ++m[it];
        for (const auto &it : m) {
            p.push(make_pair(it.second, it.first));
        }
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};
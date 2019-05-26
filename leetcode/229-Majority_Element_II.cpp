class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
		const int nums_size = nums.size();
		unordered_map<int, int> counts;
		for (auto const &itor : nums) {
			counts[itor]++;
		}
		vector<int> ans;
		for (auto const &itor : counts) {
			if (itor.second > nums_size / 3) {
				ans.push_back(itor.first);
			}
		}
		return ans;
	}
};
class Solution {
public:
   vector<string> summaryRanges(vector<int>& nums) {
		vector<vector<int>> ranges;
		vector<string> ans;
		const int nums_size = nums.size();
        if (nums_size == 0) return ans;
		vector<int> tmp({nums[0]});
		for (int i = 1; i < nums_size; ++i) {
			if (nums[i] != nums[i - 1] + 1) {
				ranges.push_back(tmp);
				tmp.clear();
			} 
			tmp.push_back(nums[i]);
		}
		ranges.push_back(tmp);
		for (auto iter : ranges) {
			string tmp_s = "";
			if (iter.size() == 1) {
				tmp_s += to_string(iter[0]);
			} else {
				tmp_s += (to_string(iter[0]) + "->" + to_string(iter[iter.size() - 1]));
			}
			ans.push_back(tmp_s);
		}
		return ans;
	}
};
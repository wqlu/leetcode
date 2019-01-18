class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        for (int i = 0; i < height.size() - 1; i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int tmp_container = (j - i) * min(height[i], height[j]);
                ans = (tmp_container > ans) ? tmp_container : ans;
            }
        }
        return ans;
    }
};
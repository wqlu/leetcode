#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int stairs = cost.size();
        if (stairs == 1) return cost[0];
        if (stairs == 2) return cost[1];
        vector<int> dp (stairs, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < stairs; i++) {
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        
        return min(dp[stairs-1], dp[stairs-2]);
    }
};

int main() {
    Solution s;
    vector<int> e ({1, 100, 1, 1, 1, 100, 1, 1, 100, 1});
    int ans = s.minCostClimbingStairs(e);
    cout << ans << endl;
    return 0;
}
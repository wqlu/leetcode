class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int gas_sum = accumulate(gas.begin(), gas.end(), 0);
		int cost_sum = accumulate(cost.begin(), cost.end(), 0);
		if (gas_sum < cost_sum) return -1;
		int result = 0;
		int sum = 0;
		for (int i = 0; i < gas.size(); ++i) {
			sum += gas[i] - cost[i];
			if (sum < 0) {
				sum = 0;
				result = i + 1;
			}
		}
		return result;

	}
};
class Solution {
public:
	int NumberOf1Between1andN_Solution(int n) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += getNumberOf1(i);
		}
		return ans;
	}

	int getNumberOf1(int i) {
		string str_i = std::to_string(i);
		int sum = 0;
		for (int i = 0; i < str_i.size(); i++) {
			if (str_i[i] == '1')
				sum ++;
		}
		return sum;
	}
};

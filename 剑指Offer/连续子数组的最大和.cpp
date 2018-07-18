#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int max_sum = array[0];
		int sum = array[0];
		for (int i = 1; i < array.size(); i++) {
			sum = sum + array[i];
            max_sum = max_sum > sum ? max_sum : sum;
			if (sum < 0)
				sum = 0;
		}
		return max_sum;
	}
};

int main()
{
	vector<int> vect;
	vect.push_back(6);
	vect.push_back(-3);
	vect.push_back(-2);
	vect.push_back(7);
	vect.push_back(-15);
	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(2);

	Solution solution;
	int ans = solution.FindGreatestSumOfSubArray(vect);
	cout << ans << endl;
	return 0;
}


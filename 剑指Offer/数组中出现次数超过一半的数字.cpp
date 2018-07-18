#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() < 1)
            return 0;
        if (numbers.size() == 1)
            return numbers[0];
        int count = 1;
        int temp = numbers[0];
        for (int i = 1; i< numbers.size(); i++) {
            if (numbers[i] == temp) {
                count++;
            } else {
                if (count == 0) {
                    temp = numbers[i];
                    count = 1;
                } else {
                    count--;
                }
            }
        }

        // check the num of temp
        int temp_num = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (temp == numbers[i]) {
                temp_num ++;
            }
        }
        if (temp_num > numbers.size()/2) {
            return temp;
        } else {
            return 0;
        }
    }
};

int main() {

    vector<int> vector1;
    vector1.push_back(1);
    vector1.push_back(2);
    vector1.push_back(3);
    vector1.push_back(2);
    vector1.push_back(2);
    vector1.push_back(2);
    vector1.push_back(5);
    vector1.push_back(4);
    vector1.push_back(2);
    Solution solution;
    int ans;
    ans = solution.MoreThanHalfNum_Solution(vector1);
    cout << ans << endl;
    return 0;
}
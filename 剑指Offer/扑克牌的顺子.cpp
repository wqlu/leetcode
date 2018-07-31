#include <iostream>
#include <vector>
#include <sort>
using namespace std;


class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        int temp [14] = {};
        for (int i = 0; i < numbers.size(); i++) {
            temp[numbers[i]] ++;
        }
        // 是否有对子
        int num = 0;
        int t = 0, sum = 0;
        for (int i = 1; i < 14; i++) {
            if (temp[i] >= 1) {
                num++;
                if (t == 0) {
                    t = i;
                } else {
                    sum = i - t - 1;
                }
                t = i;
            }
        }
        if (num + temp[0] != 5) {
            return false;
        }
        if (sum > temp[0]) {
            return false;
        }
        return true;
    }
};


int main() {
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxSum(vector<int> array, int len) {
        int a = array[0];
        int b = array[1];
        int c = array[2];
        int sum = a * b * c;
        for (int i = 3; i < len; i ++) {
            if (sum < array[i] * a * b) {
                sum = array[i] * a * b;
                c = array[i];
            }
            if (sum < array[i] * b * c) {
                sum = array[i] * b *c;
                a = array[i];
            }
            if (sum < array[i] * a * c) {
                sum = array[i] * a * c;
                b = array[i];
            }
        }
        return sum;
    }
};

int main() {
    vector<int> vect;
    vect.push_back(3);
    vect.push_back(4);
    vect.push_back(1);
    vect.push_back(2);
    Solution solution;
    int ans = solution.findMaxSum(vect, 4);
    cout << ans << endl;
    return 0;
}

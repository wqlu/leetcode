//
// Created by lu on 18-8-4.
// Email: wq.lu@outlook.com
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

/**
 * 1. 先排序
 *    特殊情况:全部相同
 * 2. 统计每种数的个数
 * 3. 计算差最小个数
 * 4. 计算差最大个数
 */

int main() {
    int n;
    while (cin >>n) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        int minNum = 0, maxNum = 0;
        // 排序
        sort(nums.begin(), nums.end());
        if (nums[0] == nums[n-1]) {
            int tmp = (n * (n - 1)) / 2;
            cout << tmp << " " << tmp << endl;
            continue;
        }

        // map来统计
        map<int, int> map_count;
        for (int i = 0; i < n; i++) {
            map_count[nums[i]] ++;
        }

        // 差最小的个数
        int minres = 0;
        if (map_count.size() == n) {
            int min = abs(nums[1] - nums[0]);
            for (int i = 2; i < n; i++) {
                int tmp = abs(nums[i] - nums[i-1]);
                if (tmp == min) {
                    minres++;
                } else if (tmp < min) {
                    minres = 1;
                    min = tmp;
                }
            }
        } else {
            // 有相同的表示min为0
            map<int, int>::iterator it;
            for (it = map_count.begin(); it != map_count.end(); it++) {
                if (it->second > 1) {
                    minres += ((it->second)*(it->second -1))/2;
                }
            }
        }
        // 差最大的个数
        int maxres = 0;

        int val1 = map_count[nums[0]];
        int val2 = map_count[nums[n-1]];
        maxres = val1 * val2;
        cout << minres << " " << maxres << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {

        int nums = stones.size();
        if (nums == 0) return 0;
        if (nums == 1) return stones[0];

        sort(stones.begin(), stones.end());
        int max_1 = stones[nums - 1];
        int max_2 = stones[nums - 2];
        stones.pop_back();
        stones.pop_back();

        if (max_1 == max_2) {
            return lastStoneWeight(stones);
        } else {
            stones.push_back(abs(max_1 - max_2));
            return lastStoneWeight(stones);
        }
        return 0;
    }
};



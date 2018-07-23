//
// Created by lu on 18-7-23.
// Email: wq.lu@outlook.com
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        int number = 0;
        int length = data.size();
        if (data.size() > 0) {
            int first = GetFirstK(data, 0, data.size()-1, k);
            int last = GetLastK(data, length, 0, data.size()-1, k);

            if (first > -1 && last >-1)
                number = last - first + 1;
        }
        return number;
    }

    int GetFirstK(vector<int> &data, int begin, int end, int k) {
        if (begin > end)
            return -1;

        int middleIndex = (end + begin) / 2;
        int middleData = data[middleIndex];

        if (middleData == k) {
            if ((middleIndex > 0 && data[middleIndex-1] != k) || middleIndex == 0)
                return middleIndex;
            else
                end = middleIndex -1;
        } else if (middleData > k)
            end = middleIndex - 1;
        else
            begin = middleIndex + 1;

        return GetFirstK(data, begin, end, k);
    }

    int GetLastK(vector<int> &data, int length, int begin, int end, int k) {
        if (begin > end)
            return -1;

        int middleIndex = (begin + end) / 2;
        int middleData = data[middleIndex];

        if (middleData == k) {
            if ((middleIndex < length - 1 && data[middleIndex + 1] != k) || middleIndex == length -1)
                return middleIndex;
            else
                begin = middleIndex + 1;
        } else if (middleData < k)
            begin = middleIndex + 1;
        else
            end = middleIndex - 1;

        return GetLastK(data, length, begin, end, k);
    }
};

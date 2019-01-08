#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if (m == 0 || n == 0) {
            return -1;
        }
        deque<int> deque1;
        for (int i = 0; i < n; i++) {
            deque1.push_back(i);
        }
        int count = 0;
        while (deque1.size() > 1) {
            int front = deque1.front();
            deque1.pop_front();
            count++;
            if (count % m == 0) {
                continue;
            } else {
                deque1.push_back(front);
            }
        }
        return deque1[0];
    }
};

int main() {
    
    return 0;
}


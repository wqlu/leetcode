#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, direction = 0;
        for (int i = 0; i < instructions.size(); ++i) {
            if (instructions[i] == 'G') {
                if (direction == up) {
                    y += 1;
                } else if (direction == left) {
                    x -= 1;
                } else if (direction == down) {
                    y -= 1;
                } else if (direction == right) {
                    x += 1;
                }
            } else if (instructions[i] == 'L') {
                direction = (direction + 1) % 4;
            } else if (instructions[i] == 'R') {
                direction = (direction + 4 - 1) % 4;
            }
        }

        if ((x == 0 && y == 0) || direction != up)
            return true;
        return false;
    }
public:
    const int up = 0;
    const int left = 1;
    const int down = 2;
    const int right = 3;
};

int main() {
    Solution s;
    bool ans = s.isRobotBounded("GGLLGG");
    cout << ans << endl;
    return 0;
}

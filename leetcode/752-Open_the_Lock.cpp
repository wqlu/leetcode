class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        const string start = "0000";
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count(start)) return -1;
        if (start == target) return 0;

        queue<string> q;
        unordered_set<string> visited{ start };

        int steps = 0;
        q.push(start);
        while (!q.empty()) {
            ++steps;
            const int size = q.size();
            for (int i = 0; i < size; ++i) {
                const string curr = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    for (int j = -1; j <= 1; j += 2) {
                        string next = curr;
                        next[i] = (next[i] - '0' + j + 10) % 10 + '0';
                        if (next == target) return steps;
                        if (dead.count(next) || visited.count(next)) continue;
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
        }
        return -1;
    }
};
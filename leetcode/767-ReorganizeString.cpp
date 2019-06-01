class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> count;
        for (char ch : S) ++count[ch];
        priority_queue<node> q;
        for (auto x : count) {
            if (x.second > (S.size() + 1) / 2) return "";
            q.push(node(x.second, x.first));
        }

        string ans = "";
        while (q.size() >= 2) {
            node a = q.top(); q.pop();
            node b = q.top(); q.pop();
            ans.push_back(a.ch);
            ans.push_back(b.ch);
            if (--a.count > 0) q.push(a);
            if (--b.count > 0) q.push(b);
        }
        if (q.size() == 1) ans += q.top().ch;
        return ans;
    }

public:
    struct node {
        int count;
        char ch;
        node(int cnt, char c) : count(cnt), ch(c) {}
        bool operator < (const node &a) const {
            if (count == a.count) return ch > a.ch;
            return count < a.count;
        }
    };
};
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string ans = "";
        sort(numbers.begin(), numbers.end(), cmp);
        for (auto i : numbers)
            ans += to_string(i);
        return ans;
    }

    static bool cmp(int a, int b) {
        string A = "";
        string B = "";
        A += to_string(a);
        A += to_string(b);
        B += to_string(b);
        B += to_string(a);

        return A < B;
    }
};
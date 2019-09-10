#include <bits/stdc++.h>
using namespace std;

int main() {
    string example;
    getline(cin, example);
    stack<char> stack;
    for (int i = 0; i < example.size(); i++) {
        if (example[i] != ']') {
            stack.push(example[i]);
        } else {
            string temp = "";
            int count = 0, index = 0;
            while (!stack.empty() && stack.top() != '[') {
                if (stack.top() >= 'A' && stack.top() <= 'Z') {
                    temp = stack.top() + temp;
                    stack.pop();
                } else if (stack.top() >= '0' && stack.top() <= '9') {
                    count = (stack.top() - '0') * (int) pow(10, index++) + count;
                    stack.pop();
                } else {
                    stack.pop();
                }
            }
            stack.pop(); // pop '['
            string res = "";
            for (int j = 0; j < count; j++) {
                res += temp;
            }
            for (int i = 0; i < res.size(); i++) {
                stack.push(res[i]);
            }
        }
    }
    string ans = "";
    while (!stack.empty()) {
        ans = stack.top() + ans;
        stack.pop();
    }
    cout << ans << endl;
    return 0;
}

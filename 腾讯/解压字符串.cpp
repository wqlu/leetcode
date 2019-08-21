#include <bits/stdc++.h>
using namespace std;

string parse(string &str) {
    int num = 0, index = 0;
    index = str.find('|');
    for (int i = 0; i < index; i++) {
        num = num * 10 + (str[i] - '0');
    }
    string tmp = str.substr(index + 1, str.size());
    string ans = "";
    while (num > 0) {
        ans += tmp;
        num--;
    }
    return ans;
}

int main() {
    string temp;
    getline(cin, temp);
    string ans = "";
    for (int i = 0; i < temp.size(); ++i) {
        if (temp[i] != ']') {
            ans += temp[i];
        } else {
            // 找到[
            string temp_str = "";
            while (ans[ans.size() - 1] != '[') {
                temp_str = ans[ans.size() - 1] + temp_str;
                ans = ans.substr(0, ans.size() - 1);
            }
            // 遇到[
            ans = ans.substr(0, ans.size() - 1);
            temp_str = parse(temp_str);
            ans += temp_str;
        }
    }
    cout << ans << endl;
    return 0;
}

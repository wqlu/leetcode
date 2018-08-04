#include <iostream>
#include <string>
using namespace std;

/**
 * 直接遍历两次，先输出小写，后输出大写
 */
int main() {
    string s;
    while (cin >> s) {
        if (s.length() >= 1 && s.length() <= 1000) {
            for (size_t i = 0; i < s.length(); i++) {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    cout << s[i];
                }
            }
            for (size_t i = 0; i < s.length(); i++) {
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    cout << s[i];
                }
            }
            cout << endl;
        }
    }
    return  0;
}

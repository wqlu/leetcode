//
// Created by lu on 18-8-6.
// Email: wq.lu@outlook.com
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    string ans = "";
    int length1 = s1.size();
    int length2 = s2.size();
    // int temp[length1 + length2] = {0};
    // 动态创建数组
    int *temp = new int[length1 + length2]();

    for (int i = 0; i < length1; i++) {
        for (int j = 0; j < length2; j++) {
            // 记得 - 1
            // 还有就是 -'0',才能变成int类型
            temp[i+j] += (s1[length1 - i - 1] - '0') * (s2[length2 - j - 1] - '0');
        }
    }

    for (int i = 0; i < length1 + length2; i++) {
        if (temp[i] >= 10) {
            temp[i+1] += (temp[i] / 10);
            temp[i] = temp[i] % 10;
        }
    }

    bool begin = true;
    for (int i = 0; i < length1 + length2; i++) {
        // 去除前面的空格
        if (begin && temp[length1 + length2 -1 -i] == 0)
            continue;
        ans += to_string(temp[length1 + length2 -1 -i]);
        begin = false;
    }
    cout << ans;
    delete[] temp;
    return 0;
}

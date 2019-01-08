//
// Created by lu on 18-9-4.
// Email: wq.lu@outlook.com
//

#include <bits/stdc++.h>
using namespace std;


// 简单直观的解决方法 -- 每一位检测
int simple(long long a) {
    unsigned int sum = 0;
    while (a) {
        if (a & 0x1) {
            sum ++;
        }
        a = a >> 1;
    }
    return sum;
}

// 可以写一下(a-1)的二进制表达试
int mid(long long a) {
    unsigned int c;
    for (c = 0; a; c++) {
        a &= a-1;
    }
    return c;
}

// 高级写法
int high(unsigned x) {
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0F0F0F0F;
    x = x + (x >> 8);
    x = x + (x >> 16);
    return x & 0x0000003F;
}

int main() {
    long long a;
    cin >> a;
    int ans1 = simple(a);
    int ans2 = mid(a);
    int ans3 = high(a);
    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;
    return 0;
}

//
// Created by lu on 18-8-9.
// Email: wq.lu@outlook.com
//

#include <bits/stdc++.h>
using namespace std;

double count_tax(int pay) {
    double tax = 0.0;
    if (pay <= 5000) {
        return 0;
    } else {
        pay = pay-5000;
    }
    while (pay > 0) {
        if (pay > 80000){
            tax += (pay - 80000)*0.45;
            pay = 80000;
        }
        if (pay > 55000) {
            tax += (pay - 55000)*0.35;
            pay = 55000;
        }
        if (pay > 35000) {
            tax += (pay - 35000)*0.30;
            pay = 35000;
        }
        if (pay > 25000) {
            tax += (pay - 25000)*0.25;
            pay = 25000;
        }
        if (pay > 12000) {
            tax += (pay - 12000)*0.20;
            pay = 12000;
        }
        if (pay > 3000) {
            tax += (pay - 3000)*0.10;
            pay = 3000;
        }
        if (pay > 0) {
            tax += (pay - 0)*0.03;
            pay = 0;
        }
    }
    return tax;
}

int main() {
    int num;
    cin >> num;
    vector<double > ans;
    for (int i = 0; i < num; i++) {
        int temp;
        double temp_ans;
        cin >> temp;
        temp_ans = count_tax(temp);
        // 四舍五入
        ans.push_back(round(temp_ans));
    }

    for (const int & i: ans) {
        cout << i << endl;
    }
    return 0;
}

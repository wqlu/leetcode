//
// Created by lu on 18-8-9.
// Email: wq.lu@outlook.com
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int num, temp, ans = 0;
    cin >> num;
    vector<int> questions;
    for (int i = 0; i < num; i++) {
        cin >> temp;
        questions.push_back(temp);
    }
    sort(questions.begin(), questions.end());
    int flag = 1;
    for (int i = 1; i < num; i++) {
        if (flag < 3) {
            flag++;
            if (questions[i] - questions[i-1] > 10) {
                ans++;
            } else {
                continue;
            }
        }
        if (flag == 3)
            flag = 1;
    }
    cout << ans + (3 - flag)<< endl;
    return 0;
}

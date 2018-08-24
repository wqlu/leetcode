//
// Created by lu on 18-8-9.
// Email: wq.lu@outlook.com
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int tower[n];
    vector<int> location;
    for (int i = 0; i < n; i++) {
        cin >> tower[i];
    }
    int total_chaju = 0, times = 0;
    for (int i = 0; i < k; i++) {
        int min_index = 0, max_index = 0;
        for (int j = 1; j < n; j++) {
            if (tower[j] > tower[max_index])
                max_index = j;
            if (tower[j] < tower[min_index])
                min_index = j;
        }
        total_chaju = tower[max_index] - tower[min_index];
        if (total_chaju == 0 || total_chaju == 1) {
            break;
        } else {
            tower[max_index]--;
            tower[min_index]++;
            times++;
            location.push_back(max_index+1);
            location.push_back(min_index+1);
        }

    }
    int mi = 0, ma = 0;
    for (int j = 1; j < n; j++) {
        if (tower[j] > tower[ma])
            ma = j;
        if (tower[j] < tower[mi])
            mi = j;
    }
    total_chaju = tower[ma] - tower[mi];

    cout << total_chaju << " " << times << endl;
    for (int i = 0; i < location.size(); i += 2) {
        cout << location[i] << " " << location[i+1] << endl;
    }
    return 0;
}
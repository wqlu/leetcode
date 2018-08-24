//
// Email: wq.lu@outlook.com
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, sum;
    vector<int> vect;
    for (int i = 0; i < 3; i++) {
        cin >> a;
        vect.push_back(a);
    }
    sort(vect.begin(), vect.end());
    if ((vect[0] + vect[1]) > (vect[0] * vect[1]))
        sum = (vect[0] + vect[1]) * vect[2];
    else
        sum = (vect[0] * vect[1]) * vect[2];
    cout << sum << endl;
    return 0;
}
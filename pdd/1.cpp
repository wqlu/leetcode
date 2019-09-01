#include <bits/stdc++.h>
using namespace std;

int getnum(string &test, int l, int r) {
    int num = 0;
    for (int i = l ; i <= r; ++i) {
        num = num * 10 + (test[i] - '0');
    }
    return num;
}

void parse(string &test, vector<int> &a, int &N) {
    int test_len = test.length();
    int l = 0, N_index = 0;
    for (int i = 0; i < test_len; ++i) {
        if (test[i] == ',') {
            a.push_back(getnum(test, l, i - 1));
            l = i + 1;
        } else if (test[i] == ';') {
            N_index = i + 1;
        } else {

        }
    }
    a.push_back(getnum(test, l, N_index - 2));
    N = getnum(test, N_index, test_len - 1);
}

bool comp(int t1, int t2) {
    bool b1 = (t1 % 2) == 0 ? true : false;
    bool b2 = (t2 % 2) == 0 ? true : false;
    if (b1 == b2) {
        return t1 > t2;
    } else {
        if (b1 == true) {
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    vector<int> a;
    string test;
    int N;
    getline(cin, test);
    parse(test, a, N);
    sort(a.begin(), a.end(), comp);
    for (int i = 0; i < N - 1; ++i) {
        cout << a[i] << "," ;
    }
    cout << a[N-1] << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    multimap<int, int> works; 
    vector<int> friends;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int D, P;
        cin >> D >> P;
        works.insert(make_pair(D, P));
    }
    multimap<int, int>::iterator it;
    for (int i = 0; i < M; i++) {
        int Ai,pay = 0;
        cin >> Ai;
        for (it = works.begin(); it != works.end(); it++) {
            if ((*it).first > Ai) {
                break;
            } else {
                pay = (*it).second > pay ? (*it).second : pay;
            }
        }
        friends.push_back(pay);
    }
    for (auto i : friends) {
        cout << i << endl;
    }
    return 0;
}


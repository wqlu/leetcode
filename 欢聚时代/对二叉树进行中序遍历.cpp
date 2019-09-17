#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void find(vector<int> &node, int Depth, int total) {
        
        cout << node[0] << endl;
        
    }
};

int main() {
    int Depth; cin >> Depth;
    int total = 1;
    for (int i = 1; i <= Depth; ++i) {
        total = total * 2;
    }
    total = total - 1;
    vector<int> node(total);
    for (int i = 0; i < total; ++i) {
        cin >> node[i];
    }
    Solution s;
    s.find(node, Depth);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Time {
    int Hi;
    int Mi;
};

int main() {
    int N; scanf("%d", &N);
    vector<int> clocks;
    for (int i = 0; i < N; ++i) {
        Time t;
        scanf("%d %d", &(t.Hi), &(t.Mi));
        clocks.push_back(t.Hi * 60 + t.Mi);
    }
    int cost; scanf("%d", &cost);
    Time ddl;
    scanf("%d %d", &(ddl.Hi), &(ddl.Mi));
    
    int ans_index;
    int ddl_time = ddl.Hi * 60 + ddl.Mi;
    sort(clocks.begin(), clocks.end());
    for (int i = 0; i < N; ++i) {
        if (clocks[i] + cost <= ddl_time) {
            ans_index = i;
            continue;
        } else {
            break;
        }
    }
    printf("%d %d", clocks[ans_index] / 60, clocks[ans_index] % 60);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define Inf 0x3f3f3f3f

int road_map[7][7];
int vis[7], dist[7];
int path[7];

void dijkstra(int u) {
    path[0] = -1;
    for (int t = 1; t <= 6; t++) { 
        dist[t] = road_map[u][t];
        path[t] = -1;
    }
    vis[u] = 1;
    for (int t = 1; t < 6; t++) {
        int minn = Inf, temp;
        for (int i = 1; i <= 6; i++) {
            if (!vis[i] && dist[i] < minn) {
                minn = dist[i];
                temp = i;
            }
        }
        vis[temp] = 1;
        for (int i = 1; i <= 6; i++) {
            if (road_map[temp][i] + dist[temp] < dist[i]) {
                dist[i] = road_map[temp][i] + dist[temp];
                path[i] = temp;
            }
        }
    }
}

int main() {

    char Start, End; cin >> Start >> End;
    int s = (int)(Start - 'A') + 1;
    int e = (int)(End - 'A') + 1;

    memset(road_map, Inf, sizeof(road_map));
    for (int i = 1; i <= 6; ++i) {
        road_map[i][i] = 0;
    }
    road_map[1][2] = 12; road_map[2][1] = 12;
    road_map[3][4] = 3; road_map[4][3] = 3;
    road_map[2][3] = 10; road_map[3][2] = 10;
    road_map[4][5] = 4; road_map[5][4] = 4;
    road_map[3][6] = 6; road_map[6][3] = 6;
    road_map[6][1] = 16; road_map[1][6] = 16;
    road_map[5][6] = 2; road_map[6][5] = 2;
    road_map[2][6] = 7; road_map[6][2] = 7;
    road_map[3][5] = 5; road_map[5][3] = 5;

    memset(vis, 0, sizeof(vis));
    
    dijkstra(s);
    cout << dist[e] << endl;
    stack<int> q;
    int x = e;
    while (path[x] != -1) {
        q.push(x);
        x = path[x];
    }
    printf("%c", 'A'+(s-1));
    while (!q.empty()) {
        printf(" %c", 'A' + (q.top()-1));
        q.pop();
    }
    cout << endl;
}

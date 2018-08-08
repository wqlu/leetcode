#include <iostream>
using namespace std;

/**
 * 迷宫问题,了解使用二维数组
 */

int main() {
    int M, N;
    cin >> M >> N;
    char **maze = new char* [M];
    
    for (int i = 0; i < M; i++) {
        maze[i] = new char[N];
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            maze[i][j] = s[j];
        }
    }


    return 0;
}

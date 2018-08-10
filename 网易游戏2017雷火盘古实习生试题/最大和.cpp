#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, D;
    cin >> N >> D;
    int matrix[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++ ) {
            cin >> matrix[i][j];
        }
    }

    int sum = 1e-7;
    // 横遍历
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - D + 1; j++) {
            int temp_sum = matrix[i][j];
            for (int k = 1; k < D; k++) {
                temp_sum += matrix[i][j+k];
            }
            if (temp_sum > sum)
                sum = temp_sum;
        }
    }

    // 竖遍历
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {
            int temp_sum = matrix[i][j];
            for (int k = 1; k < D; k++) {
                temp_sum += matrix[i+k][j];
            }

            if (temp_sum > sum)
                sum = temp_sum;
        }
    }
    // 斜下
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N -1; j++) {
            int temp_sum = matrix[i][j];
            for (int k = 1; k < D; k++) {
                temp_sum += matrix[i+k][j+k];
            }
            if (temp_sum > sum)
                sum = temp_sum;
        }
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 1; j < N; j++) {
            int temp_sum = matrix[i][j];
            for (int k = 1; k < D; k++) {
                temp_sum += matrix[i+k][j-k];
            }
            if (temp_sum > sum)
                sum = temp_sum;
        }
    }
    cout << sum << endl;
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k, d;
    cin >> n;
    int *ai = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> ai[i];
    }
    cin >> k >> d;
    long long res = 0;
    long long dpMax[n][k]; 
    long long dpMin[n][k];

    for (int i = 0; i < n; i++) {
        // max序列长度为1时，ai[i]为结尾元素，乘积序列的结果就是它本身
        dpMax[i][0] = ai[i];
        dpMin[i][0] = ai[i];
    }
  
    for (int j = 1; j < k; j++) {
        // 开始计算乘积序列长度大于1的情况
        for (int i = j; i < n; i++) {
            // 结尾元素要从j开始
            for (int x = 1; x <= d && (i - x) >= j-1; x++) {
                dpMax[i][j] = max(dpMax[i-x][j-1]*ai[i], dpMin[i-x][j-1]*ai[i]);
                dpMin[i][j] = min(dpMax[i-x][j-1]*ai[i], dpMin[i-x][j-1]*ai[i]);
            }
        }
    }
    
    // 遍历结果
    for (int i = k-1; i < n; i++) {
        if (dpMax[i][k-1] > res) {
            res = dpMax[i][k-1];
        }
    }
    cout << "Max: " << res << endl;
    return 0;
}

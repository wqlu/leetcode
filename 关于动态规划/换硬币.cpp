#include <iostream>
using namespace std;

int main() {

    int sum_coin;
    cin >> sum_coin;
    int coins[3] = {1, 3, 5};
    int Min[sum_coin+1];
    Min[0] = 0;

    for (int i = 1; i < sum_coin + 1; i++) {
        int err_coin = 9999999; // 表示无法换开
        for (auto coin : coins) {
            if (coin <= i  && Min[i - coin] + 1 < err_coin) {
                err_coin = Min[i - coin] + 1;
            }
        }
        Min[i] = err_coin;
        cout << i << "块钱需要" << Min[i] << "个硬币" << endl;
    } 
    return 0;
}

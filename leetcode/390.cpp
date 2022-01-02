/*
1. arr数组永远是一个等差数列，可以用a0+d来表示每轮的情况
2.关注何时a0会发生变化，只有left<-right，且总共有偶数个数字情况，a0->a0,其余都是a0->a0+d
*/
class Solution {
public:
    int lastRemaining(int n) {
        int remain = n;
        int loop_cnt = 0;
        int a0 = 1, d = 1;
        while (remain > 1) {
            if (remain % 2 == 1) {
                a0 = a0 + d;
            } else {
                bool left_to_right = (loop_cnt % 2 ==0);
                if (left_to_right) {
                    a0 = a0 + d;
                } else {
                    a0 = a0;
                }
            }
            loop_cnt++;
            d *= 2;
            remain /= 2;
        }
        return a0;
    }
};
class Solution {
public:
    string intToRoman(int num) {
        string ans;
        while (num) {
            if (num >= 1000) {
                for (int i = 0; i < num/1000; i++) {
                    ans += "M";
                }
                num = num % 1000;
            }
            if (num >= 500) {
                if (num / 100 == 9) {
                    ans += "CM";
                    num = num % 100;
                } else {
                    ans += "D";
                    num = num % 500;
                }
            }
            if (num >= 100) {
                if (num / 100 == 4) {
                    ans += "CD";
                } else {
                    for (int i = 0; i < num / 100; i++) {
                        ans += "C";
                    }
                }
                num = num % 100;
            }
            if (num >= 50) {
                if (num / 10 == 9) {
                    ans += "XC";
                    num = num % 10;
                } else {
                    ans += "L";
                    num = num % 50;
                }
            }
            if (num >= 10) {
                if (num / 10 == 4) {
                    ans += "XL";
                } else {
                    for (int i = 0; i < num / 10; i++) {
                        ans += "X";
                    }
                }
                num = num % 10;
            }
            if (num >= 5) {
                if (num == 9) {
                    ans += "IX";
                    num = 0;
                } else {
                    ans += "V";
                    num = num % 5;
                }
            }
            if (num >= 1) {
                if (num == 4) {
                    ans += "IV";
                } else {
                    for (int i = 0; i < num; i++) {
                        ans += "I";
                    }
                }
                num = 0;
            }
        }
        return ans;
    }
};

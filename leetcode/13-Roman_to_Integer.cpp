class Solution {
public:
        int romanToInt(string s) {
        int ans = 0;
        const int slen = s.size();
        int index = 0;
        while (index < slen) {
            switch (s[index]) {
                case 'M':
                    ans += 1000;
                    index++;
                    break;
                case 'D':
                    ans += 500;
                    index++;
                    break;
                case 'C':
                    if (index + 1 < slen ) {
                        if (s[index + 1] == 'D') {
                            ans += 400;
                            index += 2;
                            break;
                        }
                        if (s[index + 1] == 'M') {
                            ans += 900;
                            index += 2;
                            break;
                        }
                    }
                    ans += 100;
                    index++;
                    break;
                case 'L':
                    ans += 50;
                    index++;
                    break;
                case 'X':
                    if (index + 1 < slen ) {
                        if (s[index + 1] == 'L') {
                            ans += 40;
                            index += 2;
                            break;
                        }
                        if (s[index + 1] == 'C') {
                            ans += 90;
                            index += 2;
                            break;
                        }
                    }
                    ans += 10;
                    index++;
                    break;
                case 'V':
                    ans += 5;
                    index++;
                    break;
                case 'I':
                    if (index + 1 < slen ) {
                        if (s[index + 1] == 'V') {
                            ans += 4;
                            index += 2;
                            break;
                        }
                        if (s[index + 1] == 'X') {
                            ans += 9;
                            index += 2;
                            break;
                        }
                    }
                    ans += 1;
                    index++;
                    break;
            }
        }
        return ans;
    }
};
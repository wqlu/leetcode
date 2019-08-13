inline int nums(string &date, int i, int j) {
    int ret = 0;
    while ((i++) < j) {
        ret = ret*10 + (date[i-1]-'0');
    }
    return ret;
}

class Solution {
public:
    int dayOfYear(string date) {
        int year = nums(date, 0, 4);
        int month = nums(date, 5, 7);
        int day = nums(date, 8, 10);
        
        int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int ans = 0;
        for (int i = 1; i < month; i++) {
            ans += months[i - 1];
        }
        ans += day;
        if ((year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0) {
            if (month > 2) {
                ans++;
            }
        }
        return ans;
    }
};
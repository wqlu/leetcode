class Solution {
private:
    vector<string> week{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    bool is_LeapYeaw(int year) {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            return true;
        }
        return false;
    }
    int y_days(int day, int month, int year) {
        vector<int> m_days{31,28,31,30,31,30,31,31,30,31,30,31};
        if (is_LeapYeaw(year)) m_days[1] = 29;
        int res = 0;
        for (int i = 0; i <  month - 1; ++i) {
            res += m_days[i];
        }
        return res + day;
    }
public:
    string dayOfTheWeek(int day, int month, int year) {
        int day_count = y_days(day, month, year);
        for (int i = 1971; i < year; ++i) {
            if (is_LeapYeaw(i)) {
                day_count += 366;
            } else {
                day_count += 365;
            }
        }
        return week[(day_count+4) % 7];
    }
};
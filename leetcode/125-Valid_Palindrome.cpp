class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() <= 1)
            return true;
        int low = 0, high = s.length() - 1;
        bool flag = true;
        while (low < high) {
            if (!isalnum(s[low])) {
                low++;
                continue;
            }
            if (!isalnum(s[high])) {
                high--;
                continue;
            }
            if (tolower(s[low]) != tolower(s[high])) {
                flag = false;
                break;
            }
            low++;
            high--;
        }
        return flag;
    }
};
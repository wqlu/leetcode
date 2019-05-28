class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int digits_size = digits.size();
        plusOneat(digits, digits_size - 1);
        return digits;
    }

    void plusOneat(vector<int>& digits, int pos) {
        if (pos == -1) {
            digits.insert(digits.begin(), 1);
        }
        else {
            if (++digits[pos] == 10) {
                digits[pos] = 0;
                plusOneat(digits, pos - 1);
            }
        }
    }
};
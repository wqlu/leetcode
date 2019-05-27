class Solution {
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        string ans;
        while (i >= 0 || j >= 0) {
            int s = (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0) + carry;
            carry = s >> 1;
            ans += '0' + (s & 1);
        }
        if (carry) ans += '1';
        return { rbegin(ans), rend(ans) };
    }
};
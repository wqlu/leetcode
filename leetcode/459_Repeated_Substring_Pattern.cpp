class Solution {
public:
    bool repeatedSubstringPattern(string s) {
		const int s_size = s.size();
		if (s_size <= 1) return false;
		if (s_size == 2) return s[0] == s[1];
		for (int i = 2; i <= s_size; ++i) {
			if (s_size % i == 0) {
				int repeated_len = s_size / i;
				bool flag = true;
				for (int j = repeated_len; j < s_size; ++j) {
					if (s[j % repeated_len] != s[j]) {
						flag = false;
						break;
					}
				}
				if (flag) return true;
			}
		}
		return false;
	}
};
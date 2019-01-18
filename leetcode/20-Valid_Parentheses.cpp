class Solution {
public:
    bool isValid(string s) {
        stack<char> stack1;
        bool ans = true;
        const int slen = s.size();
        for (int i = 0; i < s.size(); i++) {
            switch(s[i]) {
                case '[':
                    stack1.push('[');
                    break;
                case '{':
                    stack1.push('{');
                    break;
                case '(':
                    stack1.push('(');
                    break;
                case ']':
                    if (!stack1.empty() && stack1.top() == '[') {
                        stack1.pop();
                    } else {
                        ans = false;
                    }
                    break;
                case '}':
                    if (!stack1.empty() && stack1.top() == '{') {
                        stack1.pop();
                    } else {
                        ans = false;
                    }
                    break;
                case ')':
                    if (!stack1.empty() && stack1.top() == '(') {
                        stack1.pop();
                    } else {
                        ans = false;
                    }
                    break;
                default:
                    break;
            }
            if (!ans) {
                break;
            }
        }
        if (!stack1.empty()) {
            ans = false;
        }
        return ans;
    }
};
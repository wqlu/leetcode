class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> temp;
        bool IsPopOrder = false;
        if (pushV.size() == 0 || popV.size() == 0)
            return false;

        int popIndex = 0;
        for (int i = 0; i < pushV.size(); ++i) {
            // 对于pushV来讲
            temp.push(pushV[i]);
            // 对于popV来讲
            while (!temp.empty() && temp.top() == popV[popIndex]) {
                temp.pop();
                popIndex++;
            }
        }
        return temp.empty();
    }
};
#include<iostream>
using namespace std;

class Solution {
public:
    stack<int> stack1, stack2;
    void push(int value) {
        stack1.push(value);
        if (stack2.empty() || value < stack2.top()) {
            stack2.push(value);
        } else {
            stack2.push(stack2.top());
        }
    }
    void pop() {
        stack1.pop();
        stack2.pop();
    }
    int top() {
        return stack1.top();
    }
    int min() {
        return stack2.top();
    }
};

int main() {
    cout << "hello world" << endl;
    return 0;
}

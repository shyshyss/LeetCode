//使用辅助栈来存储栈的最小元素
#include<iostream>
#include<stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> A, B;
    MinStack() {}

    void push(int x) {
        A.push(x);
        if (B.empty() || B.top() >=x) {
            B.push(x);
        }
    }

    void pop() {
        if (A.top() == B.top()) {
            B.pop();
        }
        A.pop();

    }

    int top() {
        return A.top();
    }

    int min() {
        return B.top();
    }
};

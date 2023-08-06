// problem link: https://leetcode.com/problems/implement-stack-using-queues/
// 6.8.23 (Easy)

#include <bits/stdc++.h>
using namespace std;

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

class MyStack {
public:
    // using a single queue
    queue<int> q1;

    MyStack() {
    }
    
    // TC: O(1), SC: O(1)
    void push(int x) {
        q1.push(x);
    }
    
    // TC: O(N), SC: O(N)
    int pop() {
        int res, n = q1.size()-1;
        while(n--) {
            q1.push(q1.front());
            q1.pop();
        }
        res = q1.front();
        q1.pop();
        return res;

    }
    
    // TC: O(N), SC: O(N)
    int top() {
        int res, n = q1.size()-1;
        while(n--) {
            q1.push(q1.front());
            q1.pop();
        }
        res = q1.front();
        q1.pop();
        q1.push(res);
        return res;
    }
    
    // TC: O(1), SC: O(1)
    bool empty() {
        return q1.empty();
    }
};
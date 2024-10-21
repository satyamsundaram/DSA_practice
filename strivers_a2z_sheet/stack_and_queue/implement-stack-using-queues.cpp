// https://leetcode.com/problems/implement-stack-using-queues/description/

#include <bits/stdc++.h>
using namespace std;

// using 2 queues
// class MyStack {
// private:
//     queue<int> q1, q2;

//     // transfer all ele from qa to qb except last ele of qa
//     // O(n)
//     void transfer(queue<int> &qa, queue<int> &qb) {
//         while(qa.size() != 1) {
//             int ele = qa.front();
//             qa.pop();
//             qb.push(ele);
//         }
//     }

// public:
//     MyStack() {
//     }

//     void push(int x) {
//         if(!q2.empty()) q2.push(x);
//         else q1.push(x);
//     }

//     int pop() {
//         int res;

//         if(!q2.empty()) {
//             transfer(q2, q1);
//             res = q2.front();
//             q2.pop();
//         } else {
//             transfer(q1, q2);
//             res = q1.front();
//             q1.pop();
//         }

//         return res;
//     }

//     int top() {
//         int res;

//         if(!q2.empty()) {
//             transfer(q2, q1);
//             res = q2.front();
//             q2.pop();
//             q1.push(res);
//         } else {
//             transfer(q1, q2);
//             res = q1.front();
//             q1.pop();
//             q2.push(res);
//         }

//         return res;
//     }

//     bool empty() {
//         return !(q1.size() + q2.size());
//     }
// };

// ------------------------------------------ //

// using 1 queue
class MyStack
{
private:
    queue<int> q;

    // O(n) => re-pop and push all ele except last
    int get_top(queue<int> &q)
    {
        int sz = q.size();
        for (int i = 1; i < sz; i++)
        {
            int ele = q.front();
            q.pop();
            q.push(ele);
        }

        int res = q.front();
        q.pop();
        return res;
    }

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        return get_top(q);
    }

    int top()
    {
        int res = get_top(q);
        q.push(res);
        return res;
    }

    bool empty()
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

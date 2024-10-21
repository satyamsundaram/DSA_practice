// https://leetcode.com/problems/implement-queue-using-stacks/description/

#include <bits/stdc++.h>
using namespace std;

// class MyQueue {
// private:
//     stack<int> s1, s2;

//     // O(n)
//     int get_top(stack<int> &s1, stack<int> &s2) {
//         int res;
//         while(s1.size()) {
//             res = s1.top();
//             s2.push(res);
//             s1.pop();
//         }
//         return res;
//     }

//     // O(n)
//     void retransfer(stack<int> &s2, stack<int> &s1) {
//         while(s2.size()) {
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }

// public:
//     MyQueue() {

//     }

//     void push(int x) {
//         s1.push(x);
//     }

//     // O(n) always
//     int pop() {
//         int res;
//         res = get_top(s1, s2);
//         s2.pop();
//         retransfer(s2, s1);
//         return res;
//     }

//     // O(n) always
//     int peek() {
//         int res;
//         res = get_top(s1, s2);
//         retransfer(s2, s1);
//         return res;
//     }

//     bool empty() {
//         return s1.empty();
//     }
// };

// ------------------------------------ //

// amortized: transferring & re-transferring of elements does not happen everytime after top and pop like above; instead we transfer only once whenever stack 2 or output stack is empty

class MyQueue
{
private:
    stack<int> s1, s2;

    // O(n)
    void transfer_if_s2_empty(stack<int> &s1, stack<int> &s2)
    {
        if (s2.empty())
        {
            while (s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        transfer_if_s2_empty(s1, s2);
        int res = s2.top();
        s2.pop();
        return res;
    }

    int peek()
    {
        transfer_if_s2_empty(s1, s2);
        int res = s2.top();
        return res;
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

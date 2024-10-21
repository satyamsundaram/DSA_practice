// https://leetcode.com/problems/min-stack/description/

#include <bits/stdc++.h>
using namespace std;

// // O(logn)
// class MinStack {
// private:
//     set<int> s;
//     unordered_map<int, int> um;
//     stack<int> st;

// public:
//     MinStack() {}

//     void push(int val) {
//         st.push(val);
//         um[val]++;
//         s.insert(val); // O(logn)
//     }

//     void pop() {
//         int ele = st.top();
//         st.pop();
//         um[ele]--;
//         if(!um[ele]) s.erase(ele); // O(logn)
//     }

//     int top() {
//         return st.top();
//     }

//     int getMin() {
//         set<int>::iterator itr = s.begin();
//         return *itr;
//     }
// };

// ------------------------------------------ //

// O(1): each ele of the stack also contains the min including it and the elements below it (they're kept in a pair)
class MinStack
{
private:
    stack<pair<int, int>> st;

public:
    MinStack() {}

    void push(int val)
    {
        if (st.empty())
            st.push({val, val});
        else
            st.push({val, min(val, st.top().second)});
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

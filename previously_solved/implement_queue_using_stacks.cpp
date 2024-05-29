// problem link: https://leetcode.com/problems/implement-queue-using-stacks/
// 6.8.23 (Easy)

#include <bits/stdc++.h>
using namespace std;

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

//  class MyQueue {
// public:
//     stack<int> s1, s2;
//     MyQueue() {
//     }
    
//     // TC: O(1), SC: O(1)
//     void push(int x) {
//         s1.push(x);
//     }
    
//     // TC: O(N), SC: O(N)
//     int pop() {
//         while(s1.size()>1) {
//             s2.push(s1.top());
//             s1.pop();
//         }
//         int res = s1.top();
//         s1.pop();

//         while(s2.size()) {
//             s1.push(s2.top());
//             s2.pop();
//         }

//         return res;
//     }
    
//     // TC: O(N), SC: O(N)
//     int peek() {
//         while(s1.size()>1) {
//             s2.push(s1.top());
//             s1.pop();
//         }
//         int res = s1.top();
//         s1.pop();
//         s2.push(res);

//         while(s2.size()) {
//             s1.push(s2.top());
//             s2.pop();
//         }

//         return res;
//     }
    
//     // TC: O(1), SC: O(1)
//     bool empty() {
//         return s1.empty();
//     }
// };

//-------------------------------------------------------------//

// amortised: performing n operations will take overall O(n) time even if one of those operations may take longer.

// In the first implementation of MyQueue, the pop and peek operations involve moving elements between two stacks, 
// s1 and s2, in a way that requires O(N) time and space complexity for each operation. This means that for individual pop and peek 
// operations, their time and space complexity is O(N), which does not make the operations efficient on their own.

// However, the amortized time complexity analysis considers the cost of these expensive operations over a sequence of operations. 
// In this case, after a sequence of pop and peek operations, the two stacks will eventually be emptied, and the next sequence of 
// operations can be executed in a more efficient manner. The amortized time complexity for this implementation might be lower than O(N) 
// when considering a series of operations, but it is still important to note that individual operations can be quite expensive.

// On the other hand, in the second implementation of MyQueue, the pop and peek operations are optimized by ensuring that elements are 
// only transferred between the stacks when necessary. In most cases, only a constant number of operations are required to perform a 
// single pop or peek, resulting in a more consistent and better average performance over a sequence of operations. This makes the 
// second implementation more amenable to an amortized analysis that results in a lower average cost per operation.
class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
    }
    
    // TC: O(1), SC: O(1)
    void push(int x) {
        s1.push(x);
    }
    
    // TC: O(N), SC: O(N)
    int pop() {
        int res = peek();
        s2.pop();
        return res;
    }
    
    // TC: O(N), SC: O(N)
    int peek() {
        if(s2.empty()) {
            while(s1.size()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    // TC: O(1), SC: O(1)
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
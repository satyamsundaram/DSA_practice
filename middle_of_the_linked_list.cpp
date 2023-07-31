// problem link: https://leetcode.com/problems/middle-of-the-linked-list/
// 30.7.23 (Easy)

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // naive: move a pointer from start till end and count all nodes
    // move the same pointer till ((n/2)+1)th node [1-index]
    // TC: O(n)
    // SC: O(1)
    // ListNode* middleNode(ListNode* head) {
    //     ListNode *t = head;
    //     int c = 0;
    //     while(t) {
    //         c++;
    //         t = t->next;
    //     }

    //     t = head;
    //     for(int i=1; i<=c/2; i++)
    //         t = t->next;
        
    //     return t;
    // }

    // slightly more optimized: use 2 pointers, slow and fast, when fast reaches end, wherever slow is pointing is the answer as fast will go twice the pace of slow (only one run)
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        if(fast->next == NULL) return slow;
        else fast = fast->next;

        while(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }

        return slow;
    }
};
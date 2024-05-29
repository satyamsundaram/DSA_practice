// problem link: https://leetcode.com/problems/reverse-linked-list/
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
    // iterative: use two pointers, keep reversing at each point
    // TC: O(n)
    // SC: O(1)
    // ListNode* reverseList(ListNode* head) {
    //     if(!head || !(head->next)) return head;
    //     ListNode *p = head, *q = p->next, *r = q->next;
    //     p->next = NULL;
        
    //     while(q) {
    //         q->next = p;
    //         p = q;
    //         q = r;
    //         if(r) r = r->next;
    //     }

    //     return p;
    // }

    //------------------------------------------------------------//

    // recursive: store the new head node and keep reversing the list at every recursive return
    // TC: O(n)
    // SC: O(1)
    ListNode* reverseList(ListNode* head) {
        if(!head || !(head->next)) return head;
        ListNode *reversedHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return reversedHead;
    }
};
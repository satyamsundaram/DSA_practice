// https://leetcode.com/problems/reverse-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // // iterative
    // // TC: O(N)
    // // SC: O(1)
    // ListNode* reverseList(ListNode* head) {
    //     if(!head || !head->next) return head;

    //     ListNode *p = NULL, *q = head, *r = head->next;
    //     while(q) {
    //         q->next = p;
    //         p = q;
    //         q = r;
    //         if(r) r = r->next;
    //     }

    //     return p;
    // }

    // recursive
    // TC: O(N)
    // SC: O(1)
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};

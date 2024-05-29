// problem link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// 31.7.23 (Medium)

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
    // two-pass: find the length of the LL, if we have to remove the first node, move head one node ahead, else move till we reach the node just before the node to be removed, then modify node->next = node-next->next
    // TC: O(n)
    // SC: O(1)
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     int len = 0;
    //     ListNode *copy = head;
    //     while(copy) {
    //         len++;
    //         copy = copy->next;
    //     }

    //     copy = head;
    //     n = len - n - 1;

    //     if(n<0) return head->next; // means we had to delete the first node

    //     while(n>0) {
    //         copy = copy->next;
    //         n--;
    //     }

    //     ListNode *del = copy->next;
    //     copy->next = copy->next->next;
    //     delete del;
    //     return head;
    // }

    //---------------------------------------------------//

    // one-pass: using two pointers; move one pointer n nodes ahead, then move both till the same pointer reaches the end, in this way the new pointer will reach the node just before the node to be deleted
    // TC: O(n)
    // SC: O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head;
        for(int i=1; i<=n; i++) q = q->next;
        if(!q) return p->next; // means we had to delete the first node
        while(q->next) {
            p = p->next;
            q = q->next;
        }
        ListNode *del = p->next;
        p->next = p->next->next;
        delete del;
        return head;
    }
};
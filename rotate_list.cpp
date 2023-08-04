// problem link: https://leetcode.com/problems/rotate-list/
// 4.8.23 (Medium)

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
    // method: find length of LL -> find node just before new head and modify it to point it to NULL -> modify last node to point to old head
    // TC: O(n)
    // SC: O(1)
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        
        int n = 0;
        ListNode *tmp = head, *newHead = NULL;
        
        while(tmp) {
            n++;
            tmp = tmp->next;
        }

        k = k%n;
        if(!k) return head; // means after rotation, we arrive at the same LL
        k = n-k-1;
        tmp = head;

        while(k) {
            tmp = tmp->next;
            k--;
        }

        newHead = tmp->next;
        tmp->next = NULL;
        tmp = newHead;
        if(!tmp) return newHead;
        
        while(tmp->next) tmp = tmp->next;
        tmp->next = head;
        return newHead;
    }
};
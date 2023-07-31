// problem link: https://leetcode.com/problems/merge-two-sorted-lists/
// 31.7.23 (Easy)

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
    // method: use merge sort technique
    // TC: O(m+n) where m & n are lengths of list1 and list2
    // SC: O(1)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        ListNode *t = NULL, *head;
        while(list1 && list2) {
            if(list1->val <= list2->val) {
                if(!t) {
                    t = list1;
                    head = t;
                } else {
                    t->next = list1;
                    t = t->next;
                }
                list1 = list1->next;
            } else {
                if(!t) {
                    t = list2;
                    head = t;
                }
                else {
                    t->next = list2;
                    t = t->next;
                }
                list2 = list2->next;
            }
        }

        if(list1) t->next = list1;
        if(list2) t->next = list2;

        return head;
    }
};
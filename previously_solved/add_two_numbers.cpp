// problem link: https://leetcode.com/problems/add-two-numbers/
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
    // method: add the numbers + carry and update the result into l1
    // TC: O(n)
    // SC: O(1)
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, newVal, sum;
        ListNode *t = NULL, *head = NULL;
        
        while(l1 && l2) {
            sum = l1->val + l2->val + carry;
            newVal = sum%10;
            carry = sum/10;
            if(!t) t = head = l1;
            else {
                t->next = l1;
                t = t->next;
            }
            t->val = newVal;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l2) l1 = l2;
        while(l1) {
            sum = l1->val + carry;
            newVal = sum%10;
            carry = sum/10;
            t->next = l1;
            t = t->next;
            t->val = newVal;
            l1 = l1->next;
        }

        if(carry) t->next = new ListNode(carry);
        return head;
    }
};
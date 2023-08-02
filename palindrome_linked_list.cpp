// problem link: https://leetcode.com/problems/palindrome-linked-list/
// 2.8.23 (Easy)

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
    // naive: store all node->vals in a vector and check if it's a palindrome or not using two pointers
    // TC: O(n)
    // SC: O(n)
    // bool isPalindrome(ListNode* head) {
    //     vector<int> v;
    //     while(head) {
    //         v.push_back(head->val);
    //         head = head->next;
    //     }

    //     return isPalindrome(v);
    // }

    // bool isPalindrome(vector<int> &v) {
    //     int l=0, r=v.size()-1;
    //     while(l<=r) {
    //         if(v[l]!=v[r]) return 0;
    //         l++; r--;
    //     }
    //     return 1;
    // }

    //--------------------------------------------------------------------//

    // optimized: find the middle of LL using slow and fast pointers, reverse the second half of the LL, compare first half and second half
    // TC: O(n)
    // SC: O(1)
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return 1;

        // find the middle of the LL
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second half of the LL
        ListNode *p = NULL, *q = slow->next, *r = q->next;
        while(q) {
            q->next = p;
            p = q;
            q = r;
            if(r) r = r->next;
        }
        slow->next = p;
        
        // compare first and second half of the LL
        slow = slow->next; // start of second half
        while(slow) {
            if(head->val != slow->val) return 0;
            head = head->next;
            slow = slow->next;
        }

        return 1;
    }
};
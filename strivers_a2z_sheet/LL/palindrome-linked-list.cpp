// https://leetcode.com/problems/palindrome-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // // naive: traverse list and store values in vector; check if vector is palindrome -> SC & TC: O(N)
    // bool isPalindrome(ListNode* head) {
    //     string s = "";
    //     while(head) {
    //         s += (char)head->val;
    //         head = head->next;
    //     }

    //     int l=0, r=s.size()-1;
    //     while(l<r){
    //         if(s[l] != s[r]) return 0;
    //         l++;
    //         r--;
    //     }

    //     return 1;
    // }

    // space optimized: find middle or next of middle node, reverse the second half of the list, compare the 2 halves
    bool isPalindrome(ListNode *head)
    {
        if (!head->next)
            return 1;

        ListNode *p = head, *q = head;
        while (p->next && p->next->next)
        {
            p = p->next->next;
            q = q->next;
        }

        ListNode *a = NULL, *b = q->next, *c = b->next;
        while (b)
        {
            b->next = a;
            a = b;
            b = c;
            if (c)
                c = c->next;
        }

        while (a && head)
        {
            if (head->val != a->val)
                return 0;
            a = a->next;
            head = head->next;
        }

        return 1;
    }
};

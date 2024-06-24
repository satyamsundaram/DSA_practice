// https://leetcode.com/problems/middle-of-the-linked-list/

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
    // tortoise & hare: why this works? when hare covers full list, tortoise will only cover half the list as hare travels in twice the speed of tortoise
    // TC: O(n)
    // SC: O(1)
    ListNode *middleNode(ListNode *head)
    {
        if (!head->next)
            return head;

        ListNode *p = head, *q = head;
        while (p && p->next)
        {
            p = p->next->next;
            q = q->next;
        }

        return q;
    }
};

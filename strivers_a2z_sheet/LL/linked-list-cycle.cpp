// https://leetcode.com/problems/linked-list-cycle/

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
    // approach 1: keep traversing, modify list node's values to 10^5+1; if you encounter 10^5+1 again, the loop exists, else wait for LL to end
    // approach 2: 1st one uses a lot of space, instead we can use unordered_map and store nodes in unordered_map, and repeat the same logic as above, this time checking the unordered_map for a repeat encounter

    // to save space, we can use tortoise and hare approach, once both of them enter the loop, if there is one, they'll eventually meet as by the time the tortoise will cover the full loop, the hare will have covered it twice and hence they'll both meet
    // TC: O(n)
    // SC: O(1)
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next)
            return 0;

        ListNode *p = head, *q = head;
        while (p && p->next)
        {
            p = p->next->next;
            q = q->next;
            if (p == q)
                return 1;
        }

        return 0;
    }
};

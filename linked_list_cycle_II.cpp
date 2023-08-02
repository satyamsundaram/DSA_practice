// problem link: https://leetcode.com/problems/linked-list-cycle-ii/
// 2.8.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // naive: store all the nodes in an unordered_set and if we encounter any repeated node, that is the answer else NULL
    // TC: O(n)
    // SC: O(n)
    // ListNode *detectCycle(ListNode *head) {
    //     unordered_set<ListNode*> us;
    //     while(head) {
    //         if(us.count(head)) return head;
    //         us.insert(head);
    //         head = head->next;
    //     }
    //     return NULL;
    // }

    //-----------------------------------------------------------------//

    // optimized: find the node after which cycle happens using slow and fast pointers or no cycle if fast becomes null
    // Floyd's cycle detection algorithm (tortoise and hare)
    // TC: O(n)
    // SC: O(1)
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool hasCycle = 0;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                hasCycle = 1;
                break;
            }
        }

        /* The key observation is that the number of steps taken by the slow pointer to reach the starting node of the cycle 
        is equal to the number of steps taken by the fast pointer to make a complete loop inside the cycle. 
        When they meet, they are both at the starting node of the cycle. */
        if(hasCycle) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }

        return NULL;
    }
};
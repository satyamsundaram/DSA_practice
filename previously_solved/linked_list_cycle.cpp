// problem link: https://leetcode.com/problems/linked-list-cycle/
// 1.8.23 (Easy)

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // naive: use an unordered_set to store nodes encountered, until we encounter the same node or null 
    // TC: O(n)
    // SC: O(n)
    // bool hasCycle(ListNode *head) {
    //     unordered_set<ListNode*> us;
    //     while(head) {
    //         if(us.count(head)) return 1;
    //         us.insert(head);
    //         head = head->next;
    //     }
    //     return 0;
    // }

    //----------------------------------------------------------//

    // optimized: using two pointers, fast and slow, move fast twice as fast as slow; if there is a cycle they are bound to meet, else fast'll be null
    // TC: O(n)
    // SC: O(1)
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow) return 1;
        }

        return 0;
    }
};


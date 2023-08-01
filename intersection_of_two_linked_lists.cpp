// problem link: https://leetcode.com/problems/intersection-of-two-linked-lists/
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
    // naive: us an unordered_set to store nodes after traversing list1, then traverse list2 until we encounter null or a node inside the set
    // TC: O(m+n)
    // SC: O(m+n)
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     unordered_set<ListNode*> us;
    //     while(headA) {
    //         us.insert(headA);
    //         headA = headA->next;
    //     }
    //     while(headB) {
    //         if(us.count(headB)) return headB;
    //         headB = headB->next;
    //     }

    //     return NULL;
    // }

    //---------------------------------------------------------//

    // optimized: taking the advantage here that node-val is always > 1, we can modify the node->val to be -ve for the first list traversed, for the second list traversed, check if we encounter any -ve value node or null; at the end make the -ve values +ve again
    // TC: O(m+n)
    // SC: O(1)
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode *headA2 = headA;
    //     while(headA2) {
    //         headA2->val *= -1;
    //         headA2 = headA2->next;
    //     }

    //     while(headB) {
    //         if(headB->val < 0) break;
    //         headB = headB->next;
    //     }

    //     while(headA) {
    //         headA->val *= -1;
    //         headA = headA->next;
    //     }

    //     return headB;
    // }

    //----------------------------------------------------------------//
    // optimized and generic: if node->val could also be -ve, we can use the 2 pointer approach; we move two pointers, one for each list simultaenously; if either of them becomes null, we make them point to the other list's head
    // this works because by doing the above, the two pointers, travel the same distance even if there is an intersection or not
    // when there is no intersection aftet traversing themselves and the other list, they travel equal distances and reach null
    // in the case when an intersection is present, they travel equal distances after the intersection point but before the distances can be unequal, this difference is eliminated when they are made to traverse themselves and the other list, hence they meet at the intersection
    // TC: O(m+n)
    // SC: O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;

        while(p!=q) {
            if(!p) p=headB;
            else p=p->next;

            if(!q) q=headA;
            else q=q->next;
        }

        return p; // or q
    }
};
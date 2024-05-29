// problem link: https://leetcode.com/problems/reverse-nodes-in-k-group/
// 2.8.23 (Hard)

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
    // naive: store k nodes at a time if possible, reverse them and do it recursively for the next k till possible
    // TC: O(n)
    // SC: O(k)
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;

        vector<ListNode*> v;
        ListNode *t = head;
        for(int i=0; i<k; i++) {
            if(!t) break;
            v.push_back(t);
            t = t->next;
        }

        if(v.size() != k) return head;
        
        for(int i=v.size()-1; i>0; i--)
            v[i]->next = v[i-1];
        v[0]->next = reverseKGroup(t, k);

        return v[k-1];
    }

    //------------------------------------------------------------//

    // optimized: same thing as above but without storing, aka using pointers
    // TC: O(n)
    // SC: O(1)
    // ListNode* reverseKGroup(ListNode* head, int k) {
        
    // }
};
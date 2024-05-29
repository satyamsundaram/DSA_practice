// problem link: https://leetcode.com/problems/delete-node-in-a-linked-list/
// 1.8.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // method: just shift the values after the node, one node ahead and delete the last node
    // TC: O(n)
    // SC: O(1)
    void deleteNode(ListNode* node) {
        ListNode *p = node->next;

        while(node->next) {
            node->val = p->val;
            if(!(p->next)) {
                node->next = NULL;
                delete p;
                break;
            }
            node = p;
            p = p->next;
        }
    }

    // same as above but without using any extra pointers
    // void deleteNode(ListNode* node) {
    //     while(node->next->next) {
    //         node->val = node->next->val;
    //         node = node->next;
    //     }

    //     node->val = node->next->val;
    //     delete node->next;
    //     node->next = NULL;
    // }
};
// problem link: https://leetcode.com/problems/copy-list-with-random-pointer/
// 4.8.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    // method: using a hashmap to store mappings of old nodes with new nodes using the old node's ref address as key and the new node's ref address as val
    // TC: O(n)
    // SC: O(1)
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        unordered_map<Node*, Node*> nodemap;
        Node *curr = head;
        while(curr) {
            nodemap[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while(curr) {
            nodemap[curr]->next = nodemap[curr->next];
            nodemap[curr]->random = nodemap[curr->random];
            curr = curr->next;
        }

        return nodemap[head];
    }
};
// problem link: https://leetcode.com/problems/lru-cache/
// 9.8.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// method: using deque
// TC: O(n) [TLE: as we're using while loop]
// SC: O(n)
// class LRUCache {
// public:
//     deque<pair<int, int>> dq;
//     int cap;
    
//     LRUCache(int capacity) {
//         cap = capacity;
//     }
    
//     int get(int key) {
//         int n = dq.size();
//         while(n && dq.front().first != key) {
//             dq.push_back(dq.front());
//             dq.pop_front();
//             n--;
//         }
        
//         if(!n) return -1;
//         pair<int, int> res = dq.front();
//         dq.pop_front();
//         n--;
        
//         while(n) {
//             dq.push_back(dq.front());
//             dq.pop_front();
//             n--;
//         }
        
//         dq.push_front(res);
//         return res.second;
//     }
    
//     void put(int key, int value) {
//         dq.push_front({key, value});
//         if(dq.size()>cap) dq.pop_back();
//     }
// };

//------------------------------------------------------------------//

// method: using hashmap (key, Node) and doubly linked list
// TC: O(1)
// SC: O(n)
class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node *next;
        Node *prev;
        Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };

    unordered_map<int, Node*> cache;
    int cap = 0;
    Node *head = NULL, *tail = NULL;

    void addToFront(Node *node) {
        node->prev = nullptr;
        node->next = head;
        if(head) head->prev = node;
        head = node;
        if(!tail) tail = head;
    }

    void removeNode(Node *node) {
        if(node->prev) node->prev->next = node->next;
        else head = node->next;
        if(node->next) node->next->prev = node->prev;
        else tail = node->prev;
    }
    
public:
    LRUCache(int capacity) : cap(capacity), head(nullptr), tail(nullptr) {}
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        Node *node = cache[key];
        removeNode(node);
        addToFront(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            Node *node = cache[key];
            node->value = value;
            removeNode(node);
            addToFront(node);
        } else {
            if(cache.size() >= cap) {
                cache.erase(tail->key);
                removeNode(tail);
            }
            Node *node = new Node(key, value);
            cache[key] = node;
            addToFront(node);
        }
    }
};
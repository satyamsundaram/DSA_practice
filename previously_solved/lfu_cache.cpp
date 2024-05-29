// problem link: https://leetcode.com/problems/lfu-cache/
// 10.8.23 (Hard)

#include <bits/stdc++.h>
using namespace std;

// method: using unordered mappings, we map key to {value, freq}, key to list iterator, and freq to key list. 
// minFreq is the smallest freq so far. All the keys with the same freq will be in a linked list and the LRU will be evicted if that freq is the minimum. 
// listIter stores the key's position in the linked list
// we append keys with the same freq to the end, and pop from the front
// TC: O(1)
// SC: O(n)
class LFUCache {
private:
    int cap, size=0, minFreq=0;
    unordered_map<int, pair<int, int>> kvf; // key -> {value, freq}
    unordered_map<int, list<int>::iterator> listIter; // key -> position of key in list
    unordered_map<int, list<int>> freqMap; // freq -> {key1, key2, ...}

public:
    LFUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        if(!kvf.count(key)) return -1;
        freqMap[kvf[key].second].erase(listIter[key]);
        
        kvf[key].second++;
        freqMap[kvf[key].second].push_back(key);
        listIter[key]=--freqMap[kvf[key].second].end();

        if(!freqMap[minFreq].size()) minFreq++;
        return kvf[key].first;
    }
    
    void put(int key, int value) {
        int storedValue = get(key);
        if(storedValue != -1) {
            kvf[key].first = value;
            return;
        }

        if(size>=cap) {
            kvf.erase(freqMap[minFreq].front());
            listIter.erase(freqMap[minFreq].front());
            freqMap[minFreq].pop_front();
            size--;
        }

        kvf[key] = {value, 1};
        freqMap[1].push_back(key);
        listIter[key] = --freqMap[1].end();
        minFreq=1;
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
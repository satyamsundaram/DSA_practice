// problem link: https://leetcode.com/problems/top-k-frequent-elements/
// 6.8.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct myCmp {
        bool operator()(pair<int,int>const& a, pair<int,int>const& b) {
            return a.second >= b.second;
        }
    };
public:
    // naive: find the freq of each ele using and umap; map the freq w/ all the elements of that freq; 
    // sort the freq in descending order; get the top k elements as tt is guaranteed that the answer is unique
    // TC: O(nlogn)
    // SC: O(n)
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> um;
    //     unordered_map<int, vector<int>> um2;
    //     vector<int> v, res;
        
    //     for(int n:nums) um[n]++;
    //     for(auto x:um) um2[x.second].push_back(x.first);
    //     for(auto x:um2) v.push_back(x.first);
        
    //     sort(v.begin(), v.end(), greater<int>());
        
    //     int i=0;
    //     while(k) {
    //         for(int n:um2[v[i]]) {
    //             k--;
    //             res.push_back(n);
    //         }
    //         i++;
    //     }
        
    //     return res;
    // }

    //----------------------------------------------------------------//
    
    // optimized: only store top k elements in heap
    // TC: O(klogk) + O(n)
    // SC: O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        priority_queue<pair<int,int>, vector<pair<int,int>>, myCmp> pq;
        vector<int> res;
        
        // O(n)
        for(int n:nums) um[n]++;
        
        // insert pair in min-heap and pop whenever heap size > k so that we always have top k most freq. elements
        // O(klogk)
        for(auto x:um) {
            pq.push(x);
            if(pq.size()>k) pq.pop();
        }

        // O(klogk)
        while(pq.size()) {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};
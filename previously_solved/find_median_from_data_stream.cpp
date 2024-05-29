// problem link: https://leetcode.com/problems/find-median-from-data-stream/
// 6.8.23 (Hard)

#include <bits/stdc++.h>
using namespace std;

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// naive
// class MedianFinder {
// public:
//     vector<int> v;
//     MedianFinder() {
//     }
    
//     // TC: O(n); SC: O(n)
//     void addNum(int num) {
//         v.push_back(num);
//     }
    
//     // TC: O(nlogn), SC: O(1)
//     double findMedian() {
//         sort(v.begin(), v.end());
//         int n = v.size();
//         double res;
//         if(n&1) res = v[n/2];
//         else res = (double)(v[n/2-1]+v[n/2])/2;
//         return res;
//     }
// };

//------------------------------------------------------//

// optimized: max heap stores smaller half of elements and min heap stores larger half; if an element is <= top element of maxheap, we add it to it, else we add it to min heap; we balance the heaps to ensure max heap and min heap differ in size by at max 1
class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    
    MedianFinder() { 
    }
    
    // TC: O(logn), SC: O(n)
    void addNum(int num) {
        if(maxheap.empty() || num <= maxheap.top()) maxheap.push(num);
        else minheap.push(num);

        // balance heap sizes
        if(maxheap.size() > minheap.size()+1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        } else if(minheap.size() > maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    // O(1)
    double findMedian() {
        if(maxheap.size() == minheap.size()) return (maxheap.top() + minheap.top())/2.0;
        else return maxheap.top();
    }
};
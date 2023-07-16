// problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// 16.7.23 (Easy)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // method: if my profit is +ve, keep adding, else make it zero; check max at each step
    // TC: O(n)
    // SC: O(1)
    int maxProfit(vector<int>& prices) {
        int p = 0, mx = 0;
        for(int i=1; i<prices.size(); i++) {
            p += prices[i]-prices[i-1];
            if(p<0) p=0;
            else mx = max(mx, p);
        }
        return mx;
    }
};
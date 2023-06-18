// problem link: https://www.codingninjas.com/codestudio/problems/975286
// 17-06-2023 (Easy)

#include <bits/stdc++.h>
using namespace std;

bool comparator(const pair<int, int>& p1, const pair<int, int>& p2) {
    double d1 = (double)(p1.second) / p1.first, d2 = (double)(p2.second) / p2.first;
    return d1 > d2;
}

// method: sort a/c to max value/weight and add as much weight of the higher ones
// TC: O(NlogN) + O(N) = O(NlogN)
// SC: O(1)
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), comparator);
    double res = 0;

    for(auto &p:items) {
        if(w) {
            n = min(w, p.first);
            w -= n;
            res += ((double)(p.second) * n) / p.first;
        } else break;
    }

    return res;
}
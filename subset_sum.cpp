// problem link: https://www.codingninjas.com/codestudio/problems/subset-sum_3843086
// 18-06-2023 (Easy)

#include <bits/stdc++.h> 
using namespace std;

// method: either add the sum of an element or not and then recursively call for the rest of the elements
// TC: O(2^N) + O(2^N * log(2^N)) = O(2^N * log(2^N))
// SC: O(2^N)
void helper(int sum, int i, vector<int> &num, vector<int> &res) {
    int n = num.size();
    if (i == n) {
      res.push_back(sum);
      return;
    }
    // not take
    helper(sum, i+1, num, res);

    // take
    helper(sum+num[i], i+1, num, res);
}

vector<int> subsetSum(vector<int> &num) {
    vector<int> res;
    helper(0, 0, num, res);
    sort(res.begin(), res.end());
    return res;
}
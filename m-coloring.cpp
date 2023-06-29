// problem link: https://www.codingninjas.com/studio/problems/981273
// 29.6.23 (Medium)

#include <bits/stdc++.h> 
using namespace std;

bool canColor(int i, int color, vector<vector<int>>& mat, vector<int>& v) {
    for(int j=0; j<mat.size(); j++) {
        if(mat[i][j]==1 && v[j]==color) 
            return 0;
    }
    return 1;
}

bool helper(int i, vector<vector<int>> &mat, int m, vector<int> &v) {
    int n = mat.size();
    if(i==n) return 1;
    for(int color=1; color<=m; color++) {
      if (canColor(i, color, mat, v)) {
        v[i] = color;
        if(helper(i+1, mat, m, v)) return 1;
        v[i] = 0;
      }
    }
    return 0;
}

// method: try every color on every node
// TC: O(n^m)
// SC: O(n)
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    string res = "YES";
    vector<int> v(mat.size(), 0);
    bool check = helper(0, mat, m, v);
    if(!check) res = "NO";
    return res;
}
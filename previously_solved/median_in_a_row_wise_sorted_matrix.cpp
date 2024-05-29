// problem link: https://www.codingninjas.com/studio/problems/median-of-a-row-wise-sorted-matrix_1115473
// 12.7.23 (Medium)

#include <bits/stdc++.h>
using namespace std;

// naive
// TC: O(m*n*log(m*n))
// SC: O(m*n)
// int median(vector<vector<int>> &matrix, int m, int n) {
//     // Write your code here.
//     vector<long long int> v;
//     for(auto &x:matrix) {
//         for(auto ele:x) {
//             v.push_back(ele);
//         }
//     }
//     sort(v.begin(), v.end());
//     return v[(m*n)/2];
// }

//--------------------------------------------------------------------//

 int help(vector<int>& v, int val) {   
    int low = 0, high = v.size() - 1;
    while (low <= high) {     
        int mid = low + (high-low) / 2;        
        if (v[mid] <= val) low = mid + 1;  
        else high = mid - 1;  
    }  
   return low;  
}

// method: binary search until l>r to find elements in matrix lte n
// TC: O(n * log(m))
// SC: O(1)
int median(vector<vector<int>>& matrix, int n, int m) {
   int low = 1, high = 1e9, t = m*n;
    while (low <= high) {   
        int mid = low + (high-low) / 2, count=0;  
        for(auto &row:matrix)
            count += help(row, mid);   
         if (count <= t / 2) low = mid + 1;    
        else high = mid - 1;  
    }  
   return low;
}  

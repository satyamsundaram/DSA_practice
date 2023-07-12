// problem link: https://www.codingninjas.com/studio/problems/1062679 
// 12.7.23 (Easy)

# include <bits/stdc++.h>
using namespace std;

int func(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) 
          return 2;
    }

    if (ans == m) return 1;
    return 0;
}

// method: binary search from 1 to m
// TC: O(log(m))
// SC: O(1)
int NthRoot(int n, int m) {
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        int check = func(mid, n, m);
        if (check == 1) return mid;
        else if (check == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
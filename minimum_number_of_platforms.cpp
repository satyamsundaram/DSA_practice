// problem link: https://www.codingninjas.com/codestudio/problems/799400

#include <bits/stdc++.h>
using namespace std;

// struct timing {
//     int arr;
//     int dep;
// };

// bool comparator(struct timing t1, timing t2) {
//     if(t1.arr < t2.arr) return true;
//     else if(t1.arr > t2.arr) return false;
//     else if(t1.dep < t2.dep) return true;
//     return false;
// }

// // method: for every overlapping timing, add the dep time to the min heap
// // the size of the min heap at any time is the minimum number of platforms required
// // min heap so that the earlier a train departs, the less number of extra platforms will be required

// // TC: O(N) + O(NlogN) + O(N^2 x logN) = O(N^2 x logN)
// // SC: O(N)
// int calculateMinPatforms(int at[], int dt[], int n) {
//     // Write your code here.
//     struct timing t[n];
//     for(int i=0; i<n; i++)
//         t[i].arr = at[i], t[i].dep = dt[i];

//     sort(t, t+n, comparator);
 
//     // min heap
//     priority_queue<int, vector<int>, greater<int>> pq;
//     int res = 1, c = 1;
//     pq.push(t[0].dep);

//     for(int i=1; i<n; i++) {
//       if (t[i].arr > pq.top()) {
//         while (!pq.empty() && t[i].arr > pq.top()) {
//           pq.pop();
//           c--;
//         }
//       }

//       pq.push(t[i].dep);
//       c++;
//       res = max(res, c);
//     }

//     return res;
// }

/**************************************************************************************************************/

// unlike the above method: we sort both the arrays but without taking any extra space 
// because we don't actually need to keep the arr and dep times of a train at the same index
// we don't need to keep track of which particular train will arrive or depart next, we just need to know if any will
// all we care about is going throughout the time of the day, if a train is arriving, it takes up a platform
// if a train is leaving, it empties a platform, doesn't matter which train
// and using two pointers, one to keep track of new arriving trains, 
// and the other to check which trains depart before the new one arrives

// TC: O(2NlogN) + O(2N) = O(2NlogN)
// SC: O(1)
int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at+n);
    sort(dt, dt+n);

    int c = 1, res = 1;
    int i=1, j=0;

    while(i<n && j<n) {
        if(at[i] > dt[j]) {
            c--;
            j++;
        } else {
            c++;
            i++;
        }
        res = max(res, c);
    }
    return res;
}


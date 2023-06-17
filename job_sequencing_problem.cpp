// problem link: https://www.codingninjas.com/codestudio/problems/job-sequencing-problem_1169460

#include <bits/stdc++.h>
using namespace std;

bool comparator(const vector<int> &job1, const vector<int> &job2) {
    return job1[1] > job2[1];
}

// method: to maxmimize profit, we'll sort the jobs from high profit to low
// now, to be able to do more jobs for more profit, we'll try to do a job on its deadline day or before
// TC: O(NlogN) + O(NxM) = O(NXM) where M is the max deadline
// SC: O(M)
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int m = 1, profit=0;
    for(auto job:jobs)
        m = max(m, job[0]);
    
    int done[m] = {0};
    sort(jobs.begin(), jobs.end(), comparator);

    for(auto job:jobs) {
        int i = job[0]-1;
        while(i>=0 && done[i]==1) i--;
        if(i<0) continue;
        else {
          done[i] = 1;
          profit += job[1];
        }
    }

    return profit;
}
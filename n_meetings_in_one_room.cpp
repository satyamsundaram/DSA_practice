// problem link: https://www.codingninjas.com/codestudio/problems/1062658

#include <bits/stdc++.h> 
using namespace std;

struct meeting {
    int start;
    int end;
    int pos;
};

bool comparator(struct meeting m1, meeting m2) {
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.pos < m2.pos) return true;
    return false;
}

// method: sort the meetings according to their ending time because
// the earlier a meeting finishes, the more meetings we can fit in a day
// TC: O(N) + O(NlogN) + O(N) = O(NlogN)
// SC: O(N)
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n = start.size();
    struct meeting meet[n];

    for(int i=0; i<n; i++)
        meet[i].start = start[i], meet[i].end = end[i], meet[i].pos = i+1;
    
    sort(meet, meet+n, comparator);

    vector<int> res;
    res.push_back(meet[0].pos);
    int lastMeetingEnd = meet[0].end;

    for(int i=1; i<n; i++) {
        if(meet[i].start > lastMeetingEnd) {
            res.push_back(meet[i].pos);
            lastMeetingEnd = meet[i].end;
        }
    }

    return res;
}
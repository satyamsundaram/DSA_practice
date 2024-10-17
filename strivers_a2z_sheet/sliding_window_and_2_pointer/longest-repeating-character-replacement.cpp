// https://leetcode.com/problems/longest-repeating-character-replacement/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: O(n^2) 2 nested for loops to generate all possible substrings and check freq of chars of current substr to find out if we can replace  necessary chars and make entire substr homogeneous => TLE
    // int characterReplacement(string s, int k) {
    //     int n = s.size(), res = 1;
    //     for(int i=0; i<n; i++) {
    //         unordered_map<int, int> freq;
    //         int maxFreq = 0;
    //         for(int j=i; j<n; j++) {
    //             freq[s[j]-'A']++;
    //             maxFreq = max(maxFreq, freq[s[j]-'A']);
    //             if(j-i+1 - maxFreq <= k) res = max(res, j-i+1);
    //         }
    //     }

    //     return res;
    // }

    // ------------------------------------------------------- //

    // optimized: O(n) => sliding window and check maxFreq for each window size, if more than k chars need to be changed to make substr homogeneous, increase left pointer (reduce window size)
    int characterReplacement(string s, int k)
    {
        int n = s.size(), res = 1, left = 0, maxFreq = 0;
        unordered_map<int, int> freq;

        for (int right = 0; right < n; right++)
        {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            if (right - left + 1 - maxFreq > k)
                freq[s[left++] - 'A']--;

            res = max(res, right - left + 1);
        }

        return res;
    }
};

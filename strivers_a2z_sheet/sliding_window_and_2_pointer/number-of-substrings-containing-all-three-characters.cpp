// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // // naive: O(n^2) => 2 nested for loops, inside nested loop check if we've got a,b & c, and keep counting substrings
    // int numberOfSubstrings(string s) {
    //     int cnt = 0, n = s.size();
    //     for(int i=0; i<n; i++) {
    //         int a=0, b=0, c=0;
    //         for(int j=i; j<n; j++) {
    //             if(s[j]=='a') a=1;
    //             else if(s[j]=='b') b=1;
    //             else c=1;
    //             if(a && b && c) cnt++;
    //         }
    //     }

    //     return cnt;
    // }

    // ------------------------------------ //

    // optimized: using sliding window to maintain a valid window aka with a,b & c && add n-j to cnt
    // TC: O(n)
    int numberOfSubstrings(string s)
    {
        int cnt = 0, left = 0, right = 0, n = s.size(), a = 0, b = 0, c = 0;
        while (right < n)
        {
            if (s[right] == 'a')
                a++;
            else if (s[right] == 'b')
                b++;
            else
                c++;

            while (a && b && c)
            {
                cnt += (n - right);
                if (s[left] == 'a')
                    a--;
                else if (s[left] == 'b')
                    b--;
                else
                    c--;
                left++;
            }

            right++;
        }

        return cnt;
    }
};

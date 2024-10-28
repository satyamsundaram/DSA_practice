// https://leetcode.com/problems/asteroid-collision/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool sameSign(int a, int b)
    {
        if (a < 0 && b < 0)
            return 1;
        if (a > 0 && b > 0)
            return 1;
        return 0;
    }

    // if +ve asteroid, insert into stack as it can't attack asteroids to its left; if -ve asteroid check how much previous asteroids can be destroyed; if not add it to stack; if previous to -ve asteroid is also -ve, add it to stack
    // TC & SC: O(n) as we push & pop each element only once
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size(), i = 0;
        stack<int> st;

        while (i < n)
        {
            if (st.empty() || asteroids[i] > 0 || sameSign(asteroids[i], st.top()))
                st.push(asteroids[i]);

            int f = 0;
            while (!st.empty() && asteroids[i] < 0 && !sameSign(asteroids[i], st.top()))
            {
                f = 0;
                if (abs(st.top()) == abs(asteroids[i]))
                {
                    st.pop();
                    break;
                }
                else if (abs(st.top()) < abs(asteroids[i]))
                {
                    f = 1;
                    st.pop();
                }
                else
                    break;
            }

            if (f)
                st.push(asteroids[i]);

            i++;
        }

        vector<int> res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

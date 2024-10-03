// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *child[2];

    TrieNode()
    {
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

class Solution
{
private:
    TrieNode *root;

    void insert(int n)
    {
        TrieNode *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1; // check if i-th bit is set
            if (!node->child[bit])
                node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }

    int findMaxXor(int n)
    {
        TrieNode *node = root;
        if (!node->child[0] && !node->child[1])
            return -1;

        int maxxor = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (node->child[1 - bit])
            {
                maxxor |= (1 << i);
                node = node->child[1 - bit];
            }
            else
                node = node->child[bit];
        }

        return maxxor;
    }

public:
    // // naive: nested loops
    // // TC: O(n^2); SC: O(n) => TLE
    // vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    //     vector<int> res;
    //     for(int i=0; i<queries.size(); i++) {
    //         int maxxor = -1;
    //         for(int j=0; j<nums.size(); j++) {
    //             if(nums[j] > queries[i][1]) continue;
    //             maxxor = max(maxxor, nums[j] ^ queries[i][0]);
    //         }
    //         res.push_back(maxxor);
    //     }

    //     return res;
    // }

    // -------------------------- //

    Solution()
    {
        root = new TrieNode();
    }

    // optimized: sort nums & queries (based on 2nd index)
    // TC: O(nlogn) + O(qlogq)
    // SC: O(32*n)
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        int qsz = queries.size(), nsz = nums.size();
        vector<int> res(qsz);

        vector<pair<int, pair<int, int>>> sortedQueries;
        for (int i = 0; i < qsz; i++)
            sortedQueries.push_back({queries[i][1], {queries[i][0], i}});

        sort(sortedQueries.begin(), sortedQueries.end());
        sort(nums.begin(), nums.end());

        int idx = 0;
        for (int i = 0; i < qsz; i++)
        {
            int m = sortedQueries[i].first;
            int x = sortedQueries[i].second.first;
            int queryIndex = sortedQueries[i].second.second;

            while (idx < nsz && nums[idx] <= m)
                insert(nums[idx++]);

            res[queryIndex] = findMaxXor(x);
        }

        return res;
    }
};

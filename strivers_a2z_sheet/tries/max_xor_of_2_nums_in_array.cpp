// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *child[2]; // store bit 0 & 1
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

    void insertNum(int n)
    {
        TrieNode *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int x = (n >> i) & 1; // get i-th bit value
            if (!node->child[x])
                node->child[x] = new TrieNode();
            node = node->child[x];
        }
    }

    int findMaxXor(int n)
    {
        int maxxor = 0;
        TrieNode *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int x = (n >> i) & 1;
            if (node->child[1 - x])
            {
                maxxor |= (1 << i); // set i-th bit to calculate curr xor
                node = node->child[1 - x];
            }
            else
                node = node->child[x];
        }
        return maxxor;
    }

public:
    // // naive: run nested loops to calculate xor for each combination of i,j such that i<=j
    // // TC: O(n^2); SC: O(1) -> TLE
    // int findMaximumXOR(vector<int>& nums) {
    //     int res = 0, n = nums.size();
    //     for(int i=0; i<n; i++) {
    //         for(int j=i; j<n; j++) {
    //             if(i==j) continue;
    //             res = max(res, nums[i]^nums[j]);
    //         }
    //     }
    //     return res;
    // }

    // ---------------------------- //

    Solution()
    {
        root = new TrieNode();
    }

    // optimized: store num in trie in 32-bit format; check current num with existing nums in trie to find max xor with it and any of the nums already present in the trie
    // TC: O(32 * n) to insert +  O(32 * n) to find maxxor for curr ele
    // SC: O(32 * n) to store all nums in binary format (worst case)
    int findMaximumXOR(vector<int> &nums)
    {
        int maxxor = 0, n = nums.size();
        TrieNode *node = root;

        insertNum(nums[0]);
        for (int i = 1; i < n; i++)
        {
            maxxor = max(maxxor, findMaxXor(nums[i]));
            insertNum(nums[i]);
        }

        return maxxor;
    }
};

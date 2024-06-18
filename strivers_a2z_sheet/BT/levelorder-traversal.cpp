// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // using a queue
    // TC: O(N) where N is the no. of elements in the tree
    // SC: O(N)
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};

        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> temp;
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode *qf = q.front();
                temp.push_back(qf->val);
                if (qf->left)
                    q.push(qf->left);
                if (qf->right)
                    q.push(qf->right);
                q.pop();
            }
            res.push_back(temp);
        }

        return res;
    }
};

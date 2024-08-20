// https://leetcode.com/problems/symmetric-tree/description/

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
    // TC: O(n)
    // SC: O(h)
    bool isSymmetric(TreeNode *root)
    {
        return isSameTree(root->left, root->right);
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return 1;
        if (p && !q)
            return 0;
        if (!p && q)
            return 0;
        if (p->val != q->val)
            return 0;

        return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
    }
};
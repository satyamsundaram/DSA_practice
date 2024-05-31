// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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
    // simple recursion
    // TC: O(N)
    // SC: O(N)
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> v;
        postorderHelper(root, v);
        return v;
    }

    void postorderHelper(TreeNode *root, vector<int> &v)
    {
        if (!root)
            return;
        if (root->left)
            postorderHelper(root->left, v);
        if (root->right)
            postorderHelper(root->right, v);
        v.push_back(root->val);
    }
};

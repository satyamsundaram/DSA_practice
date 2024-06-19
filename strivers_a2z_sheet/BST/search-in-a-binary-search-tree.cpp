// https://leetcode.com/problems/search-in-a-binary-search-tree/description/

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
    // traverse a tree in any order: pre/post/in; return when val matches;
    // ensure you only traverse if value is possible on the subtree a/c to bst principles: 
    // left subtree val < root and right subtree val > root
    // TC: O(n)
    // SC: o(1)
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (!root)
            return NULL;
        if (root->val == val)
            return root;
        if (val < root->val && root->left)
        {
            TreeNode *left = searchBST(root->left, val);
            if (left)
                return left;
        }
        if (val > root->val && root->right)
        {
            TreeNode *right = searchBST(root->right, val);
            if (right)
                return right;
        }
        return NULL;
    }
};
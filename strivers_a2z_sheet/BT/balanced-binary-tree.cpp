// https://leetcode.com/problems/balanced-binary-tree/description/

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
    // // TC: O(n^2) where n is the no. of nodes
    // // SC: O(d) where d is max depth of BT
    // bool isBalanced(TreeNode* root) {
    //     if(!root) return 1;
    //     if(!(isBalanced(root->left) && isBalanced(root->right))) return 0;
    //     if(abs(maxDepth(root->left) - maxDepth(root->right)) > 1) return 0;
    //     return 1;
    // }

    // int maxDepth(TreeNode* root) {
    //     if(!root) return 0;
    //     return 1 + max(maxDepth(root->left), maxDepth(root->right));
    // }

    // --------------------------------------------------- //

    // TC: O(n) where n is the no. of nodes
    // SC: O(d) d is depth
    bool isBalanced(TreeNode *root)
    {
        return checkBalance(root) != -1;
    }

    int checkBalance(TreeNode *root)
    {
        if (!root)
            return 0; // empty subtree is balanced and depth 0

        // recursively check balance of left & right subtrees
        int leftDepth = checkBalance(root->left);
        if (leftDepth == -1)
            return -1;
        int rightDepth = checkBalance(root->right);
        if (rightDepth == -1)
            return -1;

        // check if curr node is balanced
        if (abs(leftDepth - rightDepth) > 1)
            return -1;

        // return height of curr node
        return 1 + max(leftDepth, rightDepth);
    }
};
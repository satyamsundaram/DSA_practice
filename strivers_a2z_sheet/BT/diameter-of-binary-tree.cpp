// https://leetcode.com/problems/diameter-of-binary-tree/description/

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
    // // SC: O(h)
    // int diameterOfBinaryTree(TreeNode* root) {
    //     if(!root) return 0;
    //     int withRoot = maxDepth(root->left) + maxDepth(root->right);
    //     return max(max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)), withRoot);
    // }

    // int maxDepth(TreeNode *root) {
    //     if(!root) return 0;
    //     return 1 + max(maxDepth(root->left), maxDepth(root->right));
    // }

    // ----------------------------------------------- //

    // TC: O(n) where n is the no. of nodes
    // SC: O(h)
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        maxDepth(root, diameter);
        return diameter;
    }

    int maxDepth(TreeNode *root, int &diameter)
    {
        if (!root)
            return 0; // empty subtree: depth 0
        int leftDepth = maxDepth(root->left, diameter);
        int rightDepth = maxDepth(root->right, diameter);

        diameter = max(diameter, leftDepth + rightDepth);

        // return depth of curr node
        return 1 + max(leftDepth, rightDepth);
    }
};
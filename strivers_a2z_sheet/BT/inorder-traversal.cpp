// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // // recursive solution
    // // TC: O(N)
    // // SC: O(N)
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> order;
    //     inorderHelper(root, order);
    //     return order;
    // }

    // void inorderHelper(TreeNode* root, vector<int>& order) {
    //     if(!root) return;
    //     if(root->left) inorderHelper(root->left, order);
    //     order.push_back(root->val);
    //     if(root->right) inorderHelper(root->right, order);
    // }

    // iterative solution
    // TC: O(N)
    // SC: O(N)
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;
        if (!root)
            return v;
        stack<TreeNode *> st;
        TreeNode *current = root;

        while (current || !st.empty())
        {
            while (current)
            {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();
            v.push_back(current->val);

            current = current->right;
        }

        return v;
    }
};

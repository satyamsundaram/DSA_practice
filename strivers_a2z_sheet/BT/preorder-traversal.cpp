// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
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
    // recursive solution
    // TC: O(n) where n is the number of nodes in the BT
    // SC: O(n)
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> order;
    //     preorderHelper(root, order);
    //     return order;
    // }

    // void preorderHelper(TreeNode* root, vector<int> &order) {
    //     if(!root) return;
    //     order.push_back(root->val);
    //     if(root->left) preorderHelper(root->left, order);
    //     if(root->right) preorderHelper(root->right, order);
    // }

    // iterative solution
    // TC: O(n)
    // SC: O(n)
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> v;
        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *tmp = st.top();
            st.pop();
            v.push_back(tmp->val);

            if (tmp->right)
                st.push(tmp->right);
            if (tmp->left)
                st.push(tmp->left);
        }

        return v;
    }
};
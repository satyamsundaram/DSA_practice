// https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    // // for each level, push the right most node->val (iterative)
    // // TC: O(maxWidth) * O(h)
    // // SC: O(max width)
    // vector<int> rightSideView(TreeNode* root) {
    //     vector<int> res;
    //     if(!root) return res;
    //     queue<TreeNode*> q;
    //     q.push(root);

    //     while(!(q.empty())) {
    //         int sz = q.size(), f=0;
    //         for(int i=0; i<sz; i++) {
    //             TreeNode* qf = q.front();
    //             if(qf->right) q.push(qf->right);
    //             if(qf->left) q.push(qf->left);
    //             q.pop();
    //             if(!f) {
    //                 res.push_back(qf->val);
    //                 f=1;
    //             }
    //         }
    //     }

    //     return res;
    // }

    // --------------------------------------------------- //

    // using recursion
    // TC: O(n)
    // SC: O(h)
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        rightSideViewHelper(root, 1, res);
        return res;
    }

    void rightSideViewHelper(TreeNode *root, int lvl, vector<int> &res)
    {
        if (!root)
            return;
        if (lvl > res.size())
            res.push_back(root->val);
        rightSideViewHelper(root->right, lvl + 1, res);
        rightSideViewHelper(root->left, lvl + 1, res);
    }
};
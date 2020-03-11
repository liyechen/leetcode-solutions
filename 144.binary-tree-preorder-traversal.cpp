/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void preorderTraverse(TreeNode* root, vector<int>& ans) {
        if (root != NULL) {
            ans.emplace_back(root->val);
            preorderTraverse(root->left, ans);
            preorderTraverse(root->right, ans);
        }
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorderTraverse(root, ans);
        return ans;
    }
};
// @lc code=end


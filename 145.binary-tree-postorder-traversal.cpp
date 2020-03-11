/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    void postorderTraverse(TreeNode* root, vector<int>& ans) {
        if (root != NULL) {
            postorderTraverse(root->left, ans);
            postorderTraverse(root->right, ans);
            ans.emplace_back(root->val);
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorderTraverse(root, ans);
        return ans;        
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        stack<TreeNode*> treeStack;
        TreeNode* cur = root;
        while(cur != NULL || !treeStack.empty()) {
            while(cur != NULL) {
                treeStack.push(cur);
                cur = cur->left;
            }

            cur = treeStack.top();
            treeStack.pop();
            ans.push_back(cur->val);
            cur = cur->right;
        }
        return ans;
    }
};
// @lc code=end


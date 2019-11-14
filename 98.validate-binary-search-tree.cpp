/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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

    bool isBST(TreeNode* node, long minVal, long maxVal) {
        if (node == NULL) return true;

        if (node->val <= minVal || node->val >= maxVal) return false;

        return isBST(node->left, minVal, node->val) &&
            isBST(node->right, node->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};
// @lc code=end


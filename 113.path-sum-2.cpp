/*
 * Created by liyechen
 * Time 2020/04/21 17:19
 * Email <gliyechen@hotmail.com>
 */

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
    
    void dfsHelper(TreeNode* node, int sum, int inter, vector<vector<int>>& ans, vector<int> path) {
        if (node == NULL) return;
        path.push_back(node->val);
        if (node->left == NULL && node->right == NULL) {
            if (inter + node->val == sum) {
                ans.push_back(path);
            }
        }
        dfsHelper(node->left, sum, inter + node->val, ans, path);
        dfsHelper(node->right, sum, inter + node->val, ans, path);
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        dfsHelper(root, sum, 0, ans, {});
        return ans;
    }
};

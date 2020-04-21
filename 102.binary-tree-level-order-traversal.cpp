/*
 * Created by liyechen
 * Time 2020/04/21 15:50
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
    
    void orderTraverse(TreeNode* node, vector<vector<int>>& ans, int level) {
        // do something
        if (node == NULL) return;
        if (ans.size() <= level) {
            ans.push_back({});
        }
        ans[level].push_back(node->val);
        
        orderTraverse(node->left, ans, level + 1);
        orderTraverse(node->right, ans, level + 1);
    } 
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        orderTraverse(root, ans, 0);
        return ans;
    }
};

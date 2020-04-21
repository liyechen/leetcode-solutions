/*
 * Created by liyechen
 * Time 2020/04/21 17:55
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
    
    TreeNode* prev = NULL;
    
    void dfsHelper(TreeNode* node) {
        if (node == NULL) return;
        
        if (prev == NULL) prev = node;
        else {
            prev->left = node;
            prev = node;
        }
        
        dfsHelper(node->left);
        dfsHelper(node->right);
        node->right = NULL;
    } 
    
    void putLeftToRight(TreeNode* node) {
        if (node == NULL) return;
        node->right = node->left;
        node->left = NULL;
        putLeftToRight(node->right);
    }
    
public:
    void flatten(TreeNode* root) {
        dfsHelper(root);
        putLeftToRight(root);
    }
};

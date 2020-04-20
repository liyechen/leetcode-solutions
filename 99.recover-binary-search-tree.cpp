/*
 * Created by liyechen
 * Time 2020/04/20 17:58
 * Email <gliyechen@hotmail.com>
 */

class Solution {
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;
public:
    //
    // find wrong element
    // use in-order traverse to solve this problem
    //
    void recoverTree(TreeNode* root) {
        inOrderTraverse(root);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
    
    void inOrderTraverse(TreeNode* node) {
        if (node == NULL) return;
        
        inOrderTraverse(node->left);
        
        if (prev != NULL) {
            if (first == NULL && node->val <= prev->val) {
                first = prev;
            }
            if (first != NULL && node->val <= prev->val) {
                second = node;
            }
        }
        
        prev = node;  
        inOrderTraverse(node->right);
    }
};

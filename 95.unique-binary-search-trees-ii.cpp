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
    
    // generate treenodes from left to right
    vector<TreeNode*> generator(int left, int right) {
        // break
        vector<TreeNode*> res;
        if (right < left) {
            res.push_back(NULL);
            return res;
        }
        
        // pick i as root
        for (int i = left; i <= right; i++) {
            vector<TreeNode*> lefts = generator(left, i - 1);
            vector<TreeNode*> rights = generator(i + 1, right);
            for (const auto& leftNode : lefts) {
                for (const auto& rightNode : rights) {
                    TreeNode* r = new TreeNode(i);
                    r->left = leftNode;
                    r->right = rightNode;
                    res.push_back(r);
                }
            }
        }
        
        return res;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>(0);
        return generator(1, n);
    }
};

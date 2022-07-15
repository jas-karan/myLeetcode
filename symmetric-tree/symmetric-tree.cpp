/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool same(TreeNode*a, TreeNode*b){
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a->val!=b->val) return false;
        
        return same(a->left,b->right)&&same(a->right,b->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return same(root,root);
    }
};
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
    void helper(TreeNode*root,int&x){
        if(!root) return;
        helper(root->right,x);
        root->val+=x;
        x=root->val;
        helper(root->left,x);
        
        
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int x=0;
        helper(root,x);
        return root;
    }
};
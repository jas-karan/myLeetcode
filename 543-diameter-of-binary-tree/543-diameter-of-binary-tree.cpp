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
    int dia = 0;
    
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        
        auto ld = dfs(root->left);
        auto rd = dfs(root->right);
        
        dia = max(dia,ld+rd);
        return 1+max(ld,rd);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        auto ans = dfs(root);
        return dia;
    }
};
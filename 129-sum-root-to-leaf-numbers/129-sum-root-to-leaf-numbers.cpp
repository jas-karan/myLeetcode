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
    int sum = 0;
    
    void dfs(TreeNode*root,int n){
        
        if(root==NULL){
            return;
        } 
        n = n*10 + root->val;
        
        if(root->left==NULL && root->right==NULL){
           sum += n; 
        }
        
        dfs(root->left,n);
        dfs(root->right,n);
        
    }
    
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        
        return sum;
    }
};
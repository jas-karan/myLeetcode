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
    int ans=0;
    
    bool dfs(TreeNode*root){
        if(!root->left && !root->right){ans++; return true;}
        bool is=true;
        
        if(root->left) is &= dfs(root->left)&&(root->val ==root->left->val);
        if(root->right) is&=dfs(root->right)&&(root->val==root->right->val);
        
        if(is){
            ans++;
            return true;
        }
        
        return false;
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        if(root) dfs(root);
        return ans;
    }
};
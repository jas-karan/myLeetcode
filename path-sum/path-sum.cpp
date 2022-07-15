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
    int X;
    bool dfs(TreeNode*root,int cur){
        if(!root) return false;
        cur+=root->val;
        if(!root->left && !root->right) return cur==X;
        
        return dfs(root->left,cur)||dfs(root->right,cur);
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        X=targetSum;
        return dfs(root,0);
    }
};
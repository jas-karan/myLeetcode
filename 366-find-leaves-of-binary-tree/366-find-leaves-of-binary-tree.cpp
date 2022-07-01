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
    vector<vector<int>>res;
    
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        
        int height = max(dfs(root->left), dfs(root->right))+1;
        
        if(height>res.size()) res.push_back({});
        res[height-1].push_back(root->val);
        
        return height;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return res;
    }
};
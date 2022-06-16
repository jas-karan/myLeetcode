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
    unordered_map<int,int>sum;
    
    void dfs(TreeNode*root, int l){
        if(root==NULL) return;
        
        sum[l]+=root->val;
        
        dfs(root->left,l+1);
        dfs(root->right,l+1);
    }
    
    int maxLevelSum(TreeNode* root) {
        dfs(root,1);
        
        int l,s=INT_MIN;
        for(auto e:sum){
            if(e.second>s){
                s=e.second;
                l=e.first;
            }
            else if(e.second==s) l=min(l,e.first);
        }
        
        return l;
    }
};
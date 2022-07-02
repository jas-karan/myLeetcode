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
    int ans = 0;
    
    int dfs(TreeNode*node){
        if(!node) return 0;
        
        int l = dfs(node->left);
        int r = dfs(node->right);
        
        ans += abs(l)+abs(r);  //to or from via this node (ensures minimum)
        
        return l+r+node->val-1;
        
        
    }
    
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
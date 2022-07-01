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
    map<int,map<int,vector<int>>>map;
    
    void dfs(TreeNode*node,int level,int height){
        if(node==NULL) return;
        
        map[level][height].push_back(node->val);
        dfs(node->left,level-1,height+1);
        dfs(node->right,level+1,height+1);
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>>res;
        
        dfs(root,0,0);
        
        for(auto m:map){
            vector<int>curr;
            for(auto r:m.second){
                for(int val:r.second) curr.push_back(val);
            }
            res.push_back(curr);
        }
        return res;
    }
};
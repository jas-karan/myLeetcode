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
    void helper(int level,TreeNode* root, vector<int>&res){
        if(!root) return;
        
        if(res.size()<level) res.push_back(root->val);
        //res.size() => levels covered if >level that means we have already taken a node from that level
        
        helper(level+1,root->right,res);
        helper(level+1,root->left,res);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<int>res;
        
//         queue<TreeNode*>level;
        
//         level.push(root);
        
//         while(!level.empty()){
//             int sz = level.size();
            
//             for(int i=0;i<sz;i++){
                
//                 TreeNode*curr = level.front();
//                 level.pop();
                
//                 if(i==sz-1) res.push_back(curr->val);
                
//                 if(curr->left) level.push(curr->left);
//                 if(curr->right) level.push(curr->right);
//             }
//         }
        
        helper(1,root,res);
        
        return res;
    }
};
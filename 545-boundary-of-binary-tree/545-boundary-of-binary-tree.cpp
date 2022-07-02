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
    vector<int>res;
    
    void left(TreeNode*root,bool boundary){
        if(!root) return;
        
        bool leaf = !root->left && !root->right;
        
        if(boundary || leaf) res.push_back(root->val);
        
        if(!leaf){
            left(root->left,boundary);
            left(root->right,boundary&&!root->left);
        }
    }
    
    void right(TreeNode*root,bool boundary){
        if(!root) return;
        
        bool leaf = !root->left && !root->right;
        
        if(!leaf){
            right(root->left,boundary&&!root->right);
            right(root->right,boundary);
        }
        
        if(boundary || leaf) res.push_back(root->val);
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return {};
        
        res.push_back(root->val);
        left(root->left,true);
        right(root->right,true);
        
        return res;
    }
};
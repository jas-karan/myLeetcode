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
    vector<int>leaves;
    void find(TreeNode*root){
        if(root->left && root->left->left==NULL && root->left->right==NULL){
            leaves.push_back(root->left->val);
            root->left=NULL;
        }
        if(root->left) find(root->left);
        if(root->right && root->right->left==NULL && root->right->right==NULL){
            leaves.push_back(root->right->val);
            root->right=NULL;
        }
        if(root->right) find(root->right);
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>>res;
        
        while(root->left||root->right){
            leaves.clear();
            find(root);
            res.push_back(leaves);
        }
        res.push_back({root->val});
        return res;
    }
};
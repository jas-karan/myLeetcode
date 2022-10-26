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
    void find(TreeNode*root, TreeNode* &first, TreeNode* &second,TreeNode*&prev){
        if(root==NULL) return;
        
        find(root->left,first,second,prev);
        
        if(first==NULL && root->val<prev->val){
            first = prev;
        }
        if(first!=NULL && root->val<prev->val){
            second = root;
        }
        
        prev = root;
        
        find(root->right,first,second,prev);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode*first=NULL,*second=NULL;
        TreeNode*prev = new TreeNode(INT_MIN);
        find(root,first,second,prev);
        
        int t = first->val;
        first->val = second->val;
        second->val = t;
    }
};
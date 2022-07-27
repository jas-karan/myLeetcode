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
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        
        stack<TreeNode*>st;
        st.push(root);
        TreeNode*curr;
        
        TreeNode*dummy = new TreeNode();
        TreeNode*prev = dummy;
        
        while(!st.empty()){
            
            curr = st.top();
            st.pop();
            
            prev->right = curr;
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
            
            curr->left=NULL;
            prev=curr;
            
        }
        
        return;
    }
};
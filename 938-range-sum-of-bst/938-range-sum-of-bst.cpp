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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;
        
        int sum = 0;
        
        stack<TreeNode*>st;
        TreeNode*curr= root;
        
        while(curr || !st.empty()){
            
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            
            curr = st.top();
            st.pop();
            
            if(curr->val>=low && curr->val<=high) sum+=curr->val;
            
            curr = curr->right;
        }
        
        return sum;
        
    }
};
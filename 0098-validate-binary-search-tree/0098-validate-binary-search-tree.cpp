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
    bool isValidBST(TreeNode* root) {
        long long last = INT_MIN;
        last--;
        stack<TreeNode*>st;
        TreeNode*curr = root;
        
        while(st.size() || curr){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top(); st.pop();
            if(curr->val<=last) return false;
            last = curr->val;
            curr = curr->right;
        }
        
        return true;
    }
};
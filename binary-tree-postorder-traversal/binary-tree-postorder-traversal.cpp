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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>s1,s2;
        if(root)s1.push(root);
        TreeNode*cur;
        while(s1.size()){
            cur=s1.top(); s1.pop();
            s2.push(cur);
            if(cur->left) s1.push(cur->left);
            if(cur->right) s1.push(cur->right);
        }
        
        while(s2.size()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        
        return ans;
    }
};
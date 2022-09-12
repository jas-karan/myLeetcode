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
    TreeNode* findRoot(vector<TreeNode*>&ans,unordered_set<int>&del,TreeNode*root,bool isRoot){
        if(root==NULL) return NULL;
        
        bool deleted = (del.find(root->val)!=del.end());
        if(isRoot && !deleted) ans.push_back(root);
        
        root->left = findRoot(ans,del,root->left,deleted);
        root->right = findRoot(ans,del,root->right,deleted);
        
        return deleted?NULL:root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        unordered_set<int>del;
        for(int n:to_delete) del.insert(n);
        
        findRoot(ans,del,root,true);
        
        return ans;
    }
};
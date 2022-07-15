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
    unordered_map<int,int>map;
    int n;
    
    TreeNode* help(vector<int>&post,int&ind,int l,int r){
        if(l>r) return NULL;
        
        int m = map[post[ind]];
        
        TreeNode *node= new TreeNode(post[ind]);
        ind--;
        node->right = help(post,ind,m+1,r);
        node->left = help(post,ind,l,m-1);
       
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n=inorder.size();
        for(int i=0;i<n;i++) map[inorder[i]]=i;
        int ind=n-1;
        return help(postorder,ind,0,n-1);
    }
};
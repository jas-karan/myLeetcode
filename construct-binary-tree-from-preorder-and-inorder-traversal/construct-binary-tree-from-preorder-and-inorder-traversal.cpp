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
    
    TreeNode* help(vector<int>&pre,int&ind,int l,int r){
        if(l>r) return NULL;
        
        int m = map[pre[ind]];
        
        TreeNode *node= new TreeNode(pre[ind]);
        ind++;
        node->left = help(pre,ind,l,m-1);
        node->right = help(pre,ind,m+1,r);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n=inorder.size();
        for(int i=0;i<n;i++) map[inorder[i]]=i;
        int ind=0;
        return help(preorder,ind,0,n-1);
    }
};
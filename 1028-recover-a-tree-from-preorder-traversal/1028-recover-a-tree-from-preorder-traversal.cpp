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
    int nextlevel(string &s){
        if(s.length()==0) return -1;
        int i=0;
        while(i<s.length() && s[i]=='-') i++;
        return i;
    }
    
    int val(string&s){
        int pos=0;
        int v=0;
        while(pos<s.length() && s[pos]>='0' && s[pos]<='9'){ v=v*10+(s[pos]-'0'); pos++;}
        s = s.substr(pos);
        return v;
    }
    
    TreeNode* dfs(string&s,int level){
        int v = val(s);
        TreeNode* root = new TreeNode(v);
        
        int next = nextlevel(s);
        if(next==level+1){
            s=s.substr(next);
            root->left=dfs(s,next);
        }
        else root->left=NULL;
        
        next = nextlevel(s);
        if(next==level+1){
            s=s.substr(next);
            root->right=dfs(s,next);
        }
        else root->right=NULL;
        
        return root;   
    }
    
    TreeNode* recoverFromPreorder(string traversal) {
        return dfs(traversal,0);
    }
};
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
    bool dfs(string&dest, TreeNode*root, int val){
        if(root==NULL) return false;
        
        if(root->val==val) return true;
        
        if(dfs(dest,root->left,val)){ dest+='L'; return true;}
        
        if(dfs(dest,root->right,val)){ dest+='R'; return true;}
        
        return false;
        
        
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string start="",dest="";
        
        dfs(start,root,startValue);
        dfs(dest,root,destValue);
        
        while(start.size() && dest.size() && start.back()==dest.back()){
            start.pop_back();
            dest.pop_back();
        }
        
        for(int i=0;i<start.length();i++) start[i]='U';
        reverse(dest.begin(), dest.end());
        
        return start+dest;
    }
};
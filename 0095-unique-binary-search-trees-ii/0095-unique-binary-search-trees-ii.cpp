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
    vector<TreeNode*> find(int s,int e){
        
        if(s>e) return {NULL};
        
        vector<TreeNode*>curr;
        for(int i=s;i<=e;i++){
            auto lt = find(s,i-1);
            auto rt = find(i+1,e);
            
            for(auto l:lt){
                for(auto r:rt){
                    TreeNode*root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    
                    curr.push_back(root);
                }
            }
        }
        
        return curr;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>ans = 
        find(1,n);
        return ans;
    }
};
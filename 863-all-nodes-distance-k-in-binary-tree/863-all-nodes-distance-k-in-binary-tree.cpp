/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private: unordered_map<TreeNode*,TreeNode*>parent;
    
public:
    void dfs(TreeNode*root,TreeNode*par){
        if(!root) return;
        
        parent[root]=par;
        
        dfs(root->left,root);
        dfs(root->right,root);
        
        return;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //convert to graph and find kth level nodes!
        
        dfs(root,NULL);
        
        unordered_set<TreeNode*>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited.insert(target);
        visited.insert(NULL);
        
        vector<int>res;
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            if(level==k){
                for(int i=0;i<sz;i++){
                    res.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
            
            level++;
            
            for(int i=0;i<sz;i++){
                TreeNode* curr=q.front();
                q.pop();
                
                if(visited.find(curr->left)==visited.end()){ q.push(curr->left); visited.insert(curr->left);}
                if(visited.find(curr->right)==visited.end()){ q.push(curr->right); visited.insert(curr->right);}
                if(visited.find(parent[curr])==visited.end()){ q.push(parent[curr]); visited.insert(parent[curr]);}
            }
        }
        
        return res;
        
    }
};
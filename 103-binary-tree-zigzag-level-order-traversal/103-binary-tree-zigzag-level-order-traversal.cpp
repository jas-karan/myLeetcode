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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        
        deque<TreeNode*>dq;
        dq.push_front(root);
        
        vector<vector<int>>res;
        
        int level=1;
        while(!dq.empty()){
            int sz=dq.size();
            vector<int>curr;
            
            if(level&1){
                while(sz--){
                    TreeNode*node=dq.front();
                    dq.pop_front();
                    curr.push_back(node->val);
                    if(node->left) dq.push_back(node->left);
                    if(node->right) dq.push_back(node->right);
                }
            }
            else{
                while(sz--){
                    TreeNode*node=dq.back();
                    dq.pop_back();
                    curr.push_back(node->val);
                    if(node->right) dq.push_front(node->right);
                    if(node->left) dq.push_front(node->left);
                }
            }
            res.push_back(curr);
            level++;
        }
        
        return res;
    }
};
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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<pair<double,int>>pq;
        
        stack<TreeNode*>st;
        TreeNode*curr=root;
        
        while(!st.empty()||curr){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top(); st.pop();
            pq.push({abs(curr->val-target),curr->val});
            if(pq.size()>k) pq.pop();
            curr=curr->right;
        }
        
        vector<int>res;
        while(!pq.empty()){
            int val = pq.top().second;
            pq.pop();
            res.push_back(val);
        }
        
        return res;
    }
};
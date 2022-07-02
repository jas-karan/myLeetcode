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
    vector<int> closestKValues(TreeNode* root, double target, int K) {
        //sliding window -> deque
        deque<int>dq;
        
        stack<TreeNode*>st;
        TreeNode*curr=root;
        
        while(!st.empty()||curr){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top(); st.pop();
           
            if(dq.size()==K){
                if(abs(dq.front()-target)>abs(curr->val-target)){
                dq.pop_front();
                dq.push_back(curr->val);
                }
                else break;
            }
            else dq.push_back(curr->val);
            
            curr=curr->right;
        }
        
        vector<int>res;
        while(!dq.empty()){
            int val = dq.front();
            dq.pop_front();
            res.push_back(val);
        }
        
        return res;
    }
};
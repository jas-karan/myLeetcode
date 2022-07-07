/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>>res;
        
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>curr;
            int sz=q.size();
            
            while(sz--){
                Node*t=q.front();
                q.pop();
                
                curr.push_back(t->val);
                
                for(Node*child:t->children) q.push(child);
            }
            
            res.push_back(curr);
        }
        
        return res;
    }
};
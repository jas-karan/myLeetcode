/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        
        Node*prev=NULL;
        Node*itr=root;
        Node*head=NULL;
        stack<Node*>st;
        
        while(itr||!st.empty()){
            while(itr){
                st.push(itr);
                itr=itr->left;
            }
            itr=st.top(); st.pop();
            if(head==NULL) head=itr;
            itr->left=prev;
            if(prev) prev->right=itr;
            prev=itr;
            itr=itr->right;
        }
        
        prev->right=head;
        head->left=prev;
        
        return head;
    }
};
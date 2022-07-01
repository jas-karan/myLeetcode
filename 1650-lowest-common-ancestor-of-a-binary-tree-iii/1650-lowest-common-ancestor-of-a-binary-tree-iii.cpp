/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node*p1=p,*q1=q;
        while(p1!=q1){
            p1 = p1->parent==NULL ? q : p1->parent;
            q1 = q1->parent==NULL ? p : q1->parent;
        }
        
        return p1;
    }
};
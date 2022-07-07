/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL||root->left==NULL) return root;
        Node*ptr=root;
        
        while(ptr){
            ptr->left->next=ptr->right;
            ptr->right->next=(ptr->next!=NULL)?ptr->next->left:NULL;
            ptr=ptr->next;
        }
        
        root->left = connect(root->left);
        
        return root;
    }
};
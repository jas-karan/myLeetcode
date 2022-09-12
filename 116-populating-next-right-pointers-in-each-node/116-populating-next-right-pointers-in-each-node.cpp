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
        if(root==NULL || root->left==NULL) return root;
        Node*level = root;
        while(level){
            level->left->next = level->right;
            level->right->next = level->next? level->next->left: NULL;
            level = level->next;
        }
        if(root) connect(root->left);
        return root;
    }
};
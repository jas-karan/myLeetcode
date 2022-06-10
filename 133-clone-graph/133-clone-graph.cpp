/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private: unordered_map<Node*,Node*>copy;
    
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
        if(copy.find(node) != copy.end()) return copy[node];
        
        Node* currCopy = new Node(node->val,node->neighbors);
        copy[node] = currCopy;
        
        for(int i=0;i<node->neighbors.size(); i++){
            currCopy->neighbors[i] = cloneGraph(node->neighbors[i]);
        }
        
        return currCopy;
    }
};
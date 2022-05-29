/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>copy;
        
        Node* crawl = head, *newHead= NULL, *prev = NULL;
        
        while(crawl){
            Node*curr = new Node(crawl->val);
            if(newHead==NULL) newHead=curr;
            if(prev!=NULL) prev->next=curr;
            
            copy[crawl]=curr;
            prev=curr;
            crawl=crawl->next;
        }
        if(prev) prev->next=NULL;
        
        crawl=head;
        while(crawl){
            if(crawl->random){
                copy[crawl]->random = copy[crawl->random];
            }
            else copy[crawl]->random =NULL;
            
            crawl = crawl->next;
        }
        
        return newHead;
    }
};
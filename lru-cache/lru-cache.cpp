class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;
        
    Node(int _key, int _val){
        key = _key;
        val = _val;
    }
};

class LRUCache {
public:
    Node* head = new Node(-1,-1);   //assign dummy value
    Node* tail = new Node(-1,-1);
    
    unordered_map<int, Node*> m;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(Node* newNode){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    
    void deletenode(Node* delnode){
        Node* delprev = delnode->prev;    //using two pointers
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev; 
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            Node* resnode = m[key];   //get the address of the key
            int res = resnode->val;   //now get that value
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key] = head->next;      //update the key address in hashmap
            return res;               //return it's value
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* existInNode = m[key];
            m.erase(key);
            deletenode(existInNode);
        }
        
        if(m.size() == cap){             //before inserting checking map size
            m.erase(tail->prev->key);     //delete least recent used
            deletenode(tail->prev);
        }
        
        addnode(new Node(key, value));
        m[key] = head->next;          //insert the node next to head
    }
};

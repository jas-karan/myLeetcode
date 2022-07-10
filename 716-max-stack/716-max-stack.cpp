class Node{
    public:
    int val;
    Node*prev,*next;
    Node(int v){ val=v;}
};

class DLL{
    public:
    Node*head,*tail;
    
    DLL(){
        head=new Node(0);
        tail=new Node(0);
        head->next=tail;
        tail->prev=head;
    }
    
    Node* push(int val){
        Node*x = new Node(val);
        x->next = tail;
        x->prev = tail->prev;
        tail->prev->next=x;
        tail->prev=x;
        return x;
    }
    
    int top(){
        return tail->prev->val;
    }
    
    int pop(){
        Node*t = tail->prev;
        t->prev->next=tail;
        tail->prev=t->prev;
        int v = t->val;
        delete(t);
        return v;
    }
    
    int free(Node*t){
        t->prev->next=t->next;
        t->next->prev=t->prev;
        int v=t->val;
        delete(t);
        return v;
    }
};

class MaxStack {
public:
    map<int,vector<Node*>>map;
    DLL *dll;
    
    MaxStack() {
        dll = new DLL();
    }
    
    void push(int x) {
        Node*t = dll->push(x);
        map[x].push_back(t);
    }
    
    int pop() {
        int t= dll->pop();
        map[t].pop_back();
        if(map[t].size()==0) map.erase(t);
        return t;
    }
    
    int top() {
        return dll->top();
    }
    
    int peekMax() {
        auto itr = map.rbegin();
        return (itr->first);
    }
    
    int popMax() {
        int t=peekMax();
        dll->free(map[t].back());
        map[t].pop_back();
        if(map[t].size()==0) map.erase(t);
        return t;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
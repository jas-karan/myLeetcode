class MyStack {
public:
    queue<int>q;  //queue as stack
    
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        int sz = q.size();
        
        //revert the queue so that new element comes at front
        while(sz>1){
            int t = q.front();
            q.pop();
            q.push(t);
            sz--;
        }
    }
    
    int pop() {
        int val = top();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
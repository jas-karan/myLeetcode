class FreqStack {
public:
    //we need to store num with its frequency
    //we need to maintain maxfreq, to pop out
    //the only problem is what if two ele has maxfreq => need nearest to top element!
    //we can store ele with freq f in stack of that freq f
    
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>stcks;
    int maxFreq = INT_MIN;    
    
    FreqStack() {
    }
    
    void push(int val) {
        freq[val]++;
        stcks[freq[val]].push(val);
        maxFreq = max(maxFreq,freq[val]);
    }
    
    int pop() {
        int ele = stcks[maxFreq].top();
        stcks[maxFreq].pop();
        freq[ele]--;
        if(stcks[maxFreq].size()==0){
            stcks.erase(maxFreq);
            maxFreq--;
        }
        return ele;
        
        //maxFreq remains same of there are still eles with that maxFreq
        //why we need freq map? in order to put val to right freq stack!
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
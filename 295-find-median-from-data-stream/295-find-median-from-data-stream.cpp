class MedianFinder {
public:
    priority_queue<int>first;
    priority_queue<int,vector<int>,greater<int>>second;
    
    MedianFinder() {}
    
    void addNum(int num) {
        if(first.empty()){
            first.push(num);
            return;
        }
        
        if(first.size()==second.size()){
            if(second.top()<num){
                int t = second.top(); second.pop();
                first.push(t);
                second.push(num);
            }
            else{
                first.push(num);
            }
        }
        else{
            if(num<first.top()){
                int t = first.top(); first.pop();
                second.push(t);
                first.push(num);
            }
            else{
                second.push(num);
            }
        }
    }
    
    double findMedian() {
        double median = 0.0;
        
        if(first.size()==second.size()){
            median = (first.top()+second.top())/2.0;
        }
        else{
            median = first.top();
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
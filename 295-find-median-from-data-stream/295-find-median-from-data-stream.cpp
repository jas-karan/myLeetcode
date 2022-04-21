class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>>p2;
    priority_queue<int>p1;
    
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(p1.size()==p2.size()){
            if(!p2.empty()&&num>p2.top()){
                int t=p2.top(); p2.pop();
                p1.push(t);
                p2.push(num);
            }
            else p1.push(num);
        }
        else{
            if(num<p1.top()){
                int t=p1.top();
                p1.pop();
                p2.push(t);
                p1.push(num);
            }
            else p2.push(num);
        }
    }
    
    double findMedian() {
        
        double median;
        if(p1.size()>p2.size()) median = p1.top();
        else{
            median = (p1.top()+p2.top())/2.0;
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
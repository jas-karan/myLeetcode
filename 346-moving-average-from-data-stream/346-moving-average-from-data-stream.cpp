class MovingAverage {
public:
    int size;
    deque<int>window;
    int sum=0;
    
    MovingAverage(int size) {
        this->size=size;
    }
    
    double next(int val) {
        window.push_back(val);
        sum+=val;
        if(window.size()>size){
            sum-=window.front();
            window.pop_front();
        }
        return (sum*1.0)/window.size();
        
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
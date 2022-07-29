class Vector2D {
public:
    deque<int>dq;
    
    Vector2D(vector<vector<int>>& vec) {
        for(auto v:vec) for(int i:v) dq.push_back(i);
    }
    
    int next() {
        int a=dq.front();
        dq.pop_front();
        return a;
    }
    
    bool hasNext() {
        return dq.empty()==false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
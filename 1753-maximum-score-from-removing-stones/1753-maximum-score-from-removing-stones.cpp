class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        if(a) pq.push(a);
        if(b) pq.push(b);
        if(c) pq.push(c);
        int res=0;
        while(pq.size()>=2){
            int x=pq.top();pq.pop();
            int y=pq.top();pq.pop();
            
            res+=1;
            if(--x) pq.push(x);
            if(--y) pq.push(y);
        }
        
        return res;
    }
};
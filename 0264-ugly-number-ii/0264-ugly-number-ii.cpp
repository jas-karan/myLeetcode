class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>,greater<long>>pq;
        if(n==1) return 1;
        
        pq.push(1);
        long t = 1;
        while(n>0){
            t = pq.top(); pq.pop();
            while(pq.size() && pq.top()==t) pq.pop();
            pq.push(t*2);
            pq.push(t*3);
            pq.push(t*5);
            n--;
        }
        
        return t;
    }
};
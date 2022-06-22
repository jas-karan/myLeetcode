class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int sum = 0;
        for(int i:piles){
            pq.push(i);
            sum+=i;
        }
        while(k-- && pq.size()){
            int x = pq.top(); pq.pop();
            int y = floor(x/2);
            sum-=y;
            x-=y;
            if(x) pq.push(x);
        }
        
        return sum;
    }
};
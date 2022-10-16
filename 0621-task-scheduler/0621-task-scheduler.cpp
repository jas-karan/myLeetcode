class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(char c:tasks) mp[c]++;
        
        priority_queue<int>pq;
        for(auto e:mp) pq.push(e.second);
        
        int cycle = n+1;
        int time = 0;
        
        while(pq.size()){
            int t = 0;
            vector<int>v;
            for(int i=0;i<cycle;i++){
                if(pq.size()){
                    v.push_back(pq.top());
                    pq.pop();
                    t++;
                }
            }
            
            for(int e:v){
                if(--e) pq.push(e);
            }
            
            //if there is something left then we have to wait for cycle time else add current time
            time+=pq.size()?cycle:t; 
        }
        
        return time;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        
        unordered_map<char,int>m;
        for(auto ch : tasks) m[ch]++;
    
        priority_queue<int> q;
        for(auto x:m) q.push(x.second);
        
        int cycles=0;
        while(!q.empty())
        {
            vector<int>temp; //do each process one time
            for(int i=0;i<=n;i++)  //n+1 reqd
            {
                if(!q.empty())
                {
                    temp.push_back(q.top());
                    q.pop();
                }
            }
            
            for(int i:temp)
            {
                if(--i>0)
                    q.push(i);
            }
            
            cycles+= q.empty()? temp.size():n+1;
        }
        
        return cycles;
    }
};
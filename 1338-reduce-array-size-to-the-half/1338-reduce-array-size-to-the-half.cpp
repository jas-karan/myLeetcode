class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>map;
        for(int i:arr) map[i]++;
        
        priority_queue<int>pq;
        for(auto m:map) pq.push(m.second);
        
        int cnt=0;
        int ans=0;
        while(cnt<arr.size()/2){
            cnt+=pq.top();
            pq.pop();
            ans++;
        }
        
        return ans;
    }
};
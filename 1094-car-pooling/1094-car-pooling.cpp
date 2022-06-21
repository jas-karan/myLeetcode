class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        sort(trips.begin(),trips.end(),[](vector<int> &a,vector<int> &b){
            return a[1]<b[1];  
        });
        int curr=0;
        for(int i=0;i<trips.size();i++){
            while(pq.size()>0 and (pq.top()).first<=trips[i][1]) {
                curr-=pq.top().second;
                pq.pop();
            }
            if(curr+trips[i][0]>capacity)  return false;
            pq.push({trips[i][2],trips[i][0]});
            curr+=trips[i][0];
        }
        return true;
    }
};
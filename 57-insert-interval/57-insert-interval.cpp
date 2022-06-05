class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
    
        int i = 0;
        while(i<intervals.size() && intervals[i][1]<newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }
        
        auto curr = newInterval;
        for(i;i<intervals.size();i++){
            if(intervals[i][0]<=curr[1]){
                curr[1] = max(intervals[i][1],curr[1]);
                curr[0] = min(intervals[i][0],curr[0]);
            }
            else{
                res.push_back(curr);
                curr=intervals[i];
            }
        }
        res.push_back(curr);
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        
        auto curr = intervals[0];
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=curr[1]){
                curr[1] = max(intervals[i][1],curr[1]);
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
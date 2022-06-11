class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>merged;
        
        sort(intervals.begin(), intervals.end());
        vector<int> curr = intervals[0];
        
        for(int i=1;i<intervals.size();i++){
            if(curr[1]>=intervals[i][0]){
                curr[1] = max(curr[1], intervals[i][1]);
            }
            else{
                merged.push_back(curr);
                curr=intervals[i];
            }
        }
        
        merged.push_back(curr);
        
        return merged;
    }
};
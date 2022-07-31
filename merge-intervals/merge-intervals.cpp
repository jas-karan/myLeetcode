class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n = intervals.size();
        sort(begin(intervals),end(intervals));
        vector<int>v = intervals[0];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=v[1]){
                v[1] = max(intervals[i][1],v[1]);
            }
            else{
                ans.push_back(v);
                v = intervals[i];
            }
        }
        ans.push_back(v);
        return ans;
    }
};
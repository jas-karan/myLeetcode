class Solution {
public:
    static bool comp(vector<int> a,vector<int> b){
        return (a[0]!=b[0]) ? a[0]<b[0]: a[1]>b[1];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),comp);
        
        int covered = 0;
        int max_end = intervals[0][1];
        
        for(int i=1;i<n;i++){
            if(intervals[i][1]<=max_end) covered++;
            max_end = max(max_end,intervals[i][1]);
        }
        
        return n-covered;
    }
};
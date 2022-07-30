class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>>res;
        
        int n = s.length();
        
        int l=0,r=0;
        for(r=0;r<n;r++){
            if(r==0 || s[r]==s[r-1]) continue;
            if(r-l>=3){
                res.push_back({l,r-1});
            }
            l=r;
        }
        if(r-l>=3) res.push_back({l,r-1});
        return res;
    }
};
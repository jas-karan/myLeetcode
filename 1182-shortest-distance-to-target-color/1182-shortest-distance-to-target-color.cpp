class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> cindex(4);
        for(int i=0;i<colors.size();i++) cindex[colors[i]].push_back(i);
        vector<int> res;
        for(auto& q : queries){
            int i = q[0], c = q[1];
            auto& v = cindex[c];
            int j = lower_bound(v.begin(), v.end(), i) - v.begin();
            int ans = 1e5;
            if(j < v.size()) ans = v[j]-i;
            if(j != 0) ans = min(ans, i - v[j-1]);
            res.push_back(ans == 1e5 ? -1 : ans);
        }
        return res;
    }
};
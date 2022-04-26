class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        
        sort(points.begin(), points.end());
        
        for(int i=0; i<queries.size(); i++){
            
            auto& q = queries[i];
            
            int x = q[0], y = q[1], r = q[2];
            
            //points must lie in range [x-r,x+r]  --- Optimization
            
            auto it = lower_bound(points.begin(), points.end(), vector<int>{x-r,0});
            
            for(; it != points.end() and (*it)[0] <= x+r; it++){
                
                int d2 = ((*it)[0]-x)*((*it)[0]-x) + ((*it)[1]-y)*((*it)[1]-y);
                
                if(d2 <= r*r) ans[i]++;
                
            }
            
        }
        
        return ans;
    }
};
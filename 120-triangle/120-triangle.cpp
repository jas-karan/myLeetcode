class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int res = INT_MAX;
        
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(j==0) triangle[i][j]+=triangle[i-1][j];
                else if(j==triangle[i].size()-1) triangle[i][j]+=triangle[i-1][j-1];
                else{
                    triangle[i][j]+=min(triangle[i-1][j],triangle[i-1][j-1]);
                }
            }
        }
        
        for(int j=0;j<triangle[triangle.size()-1].size();j++){
            res = min(res,triangle[triangle.size()-1][j]);
        }
        
        return res;
    }
};
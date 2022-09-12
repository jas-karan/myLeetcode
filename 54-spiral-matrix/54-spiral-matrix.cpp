class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m = matrix.size(), n = matrix[0].size();
        
        int l=0,d=n-1,r=m-1,u=0;
        
        while(l<=r && u<=d){
            for(int j=u;j<=d;j++) ans.push_back(matrix[l][j]);
            l++;
            for(int i=l;i<=r;i++) ans.push_back(matrix[i][d]);
            d--;
            if(l<=r){
                for(int j=d;j>=u;j--) ans.push_back(matrix[r][j]);
                r--;
            }
            if(u<=d){
                for(int i=r;i>=l;i--) ans.push_back(matrix[i][u]);
                u++;
            }
        }
        
        return ans;
    }
};
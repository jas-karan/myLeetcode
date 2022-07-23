class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m=matrix.size();
        int n=matrix[0].size();
        
        int r=0,d=n-1,l=m-1,u=0;
        
        while(r<=l && u<=d){
            for(int j=u;j<=d;j++) ans.push_back(matrix[r][j]);
            r++;
            for(int i=r;i<=l;i++) ans.push_back(matrix[i][d]);
            d--;
            if(r<=l){
                for(int j=d;j>=u;j--) ans.push_back(matrix[l][j]);
                l--;
            }
            if(u<=d){
                for(int i=l;i>=r;i--) ans.push_back(matrix[i][u]);
                u++;
            }
        }
        
        return ans;
    }
};
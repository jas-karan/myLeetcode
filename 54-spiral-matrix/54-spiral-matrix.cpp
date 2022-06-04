class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int l=0,t=n-1,r=m-1,b=0;
        
        while(l<=r && b<=t){
            for(int i=b;i<=t;i++) ans.push_back(matrix[l][i]); l++;
            for(int i=l;i<=r;i++) ans.push_back(matrix[i][t]); t--;
            if(l<=r) for(int i=t;i>=b;i--) ans.push_back(matrix[r][i]); r--;
            if(b<=t) for(int i=r;i>=l;i--) ans.push_back(matrix[i][b]); b++;
        }
        
        return ans;
    }
};
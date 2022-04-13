class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        int l=0,t=n-1,r=n-1,b=0,el=1;
        
        while(l<=r && b<=t){
            for(int i=b;i<=t;i++){
                ans[l][i]=el++;
            }
            l++;
            for(int i=l;i<=r;i++){
                ans[i][t]=el++;
            }
            t--;
            for(int i=t;i>=b;i--){
                ans[r][i]=el++;
            }
            r--;
            for(int i=r;i>=l;i--){
                ans[i][b]=el++;
            }
            b++;
        }
        
        return ans;
    }
};
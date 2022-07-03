class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int m=destination[0],n=destination[1];
        
        vector<vector<int>>cnt(m+1,vector<int>(n+1,0));
        
        //cnt(i,j) strings from (i,j)
        for(int i=m;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(i==m || j==n) cnt[i][j]=1;
                else{
                   cnt[i][j] = cnt[i+1][j]+cnt[i][j+1]; 
                }
            }
        }
        
        //for small strings, H<V
        
        int i=0,j=0;
        string ans="";
        
        while(i<m && j<n){
            if(cnt[i][j+1]>=k){
                ans+='H';
                j++;
            }
            else{
                ans+='V';
                k-=cnt[i][j+1];
                i++;
            }
        }
        
        while(i<m){ans+='V'; i++;}
        while(j<n){ans+='H'; j++;}
        
        return ans;
        
    }
};
class Solution {
public:
    int dp[1001][1001];
    int solve(string txt, int b, int e){
        if(e<b) return 0;  
        int res=1;  
        int len=1;  
        if(dp[b][e]!=-1) return dp[b][e];
        for(int i=e; i>b; i--,len++){
            if(txt[b]==txt[i]){
                string suff = txt.substr(i,len);
                string pref = txt.substr(b,len);
                if(suff==pref) res = max(res,2+solve(txt,b+len,i-1));
            }
        }
        return dp[b][e]=res;
    }
    
    int longestDecomposition(string text) {
        int n = text.size();
        memset(dp,-1,sizeof dp);
        int ans = solve(text,0,n-1);
        return ans;
    }
};
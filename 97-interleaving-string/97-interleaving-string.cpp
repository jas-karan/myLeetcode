class Solution {
public:
    int memo[101][101];
    int n,m;
    
    int dfs(string s1,int i,string s2,int j,string s3,int k){
        if(i==n) return s2.substr(j)==s3.substr(k);
        if(j==m) return s1.substr(i)==s3.substr(k);
        
        if(memo[i][j]!=-1) return memo[i][j];
        
        if(s1[i]==s3[k] && dfs(s1,i+1,s2,j,s3,k+1) || s2[j]==s3[k] && dfs(s1,i,s2,j+1,s3,k+1))
            memo[i][j]=1;
        else memo[i][j]=0;
        
        return memo[i][j];
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        n=s1.length();
        m=s2.length();
        if(n+m!=s3.length()) return false;
        
        memset(memo,-1,sizeof(memo));
        return dfs(s1,0,s2,0,s3,0);
    }
};
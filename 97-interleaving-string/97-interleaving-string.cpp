class Solution {
public:
    int mem[101][101];
    bool dfs(string s1,string s2,string s3,int i,int j,int k){
        if(i==s1.length()) return s2.substr(j)==s3.substr(k);
        if(j==s2.length()) return s1.substr(i)==s3.substr(k);
        
        if(mem[i][j]!=-1) return mem[i][j];
        
        bool ans=false;
        if(i<s1.length() && s1[i]==s3[k]){
            ans = ans || dfs(s1,s2,s3,i+1,j,k+1);
        }
        if(j<s2.length() && s2[j]==s3[k]){
            ans = ans || dfs(s1,s2,s3,i,j+1,k+1);
        }
        return mem[i][j]=ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        memset(mem,-1,sizeof(mem));
        return dfs(s1,s2,s3,0,0,0);
    }
};
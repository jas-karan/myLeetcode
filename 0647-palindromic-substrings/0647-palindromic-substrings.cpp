class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>>mem(n,vector<bool>(n,false));
        int cnt=0;
        for(int len=1;len<=n;len++){
            for(int i=0,j=len-1;j<n;i++,j++){
                if(len==1)  mem[i][j]=true;
                else if(len==2 && s[i]==s[j]) mem[i][j]=true;
                else if(s[i]==s[j] && mem[i+1][j-1]) mem[i][j]=true;
                if(mem[i][j]) cnt++;
            }
        }
        return cnt;
    }
};
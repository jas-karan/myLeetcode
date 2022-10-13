class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        
        int n = s.length();
        vector<vector<int>>mem(n+1,vector<int>(n+1,0));
        int len = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    mem[i][j] = 1+mem[i-1][j-1];
                }
                else{
                    mem[i][j] = max(mem[i-1][j],mem[i][j-1]);
                }
                len = max(len, mem[i][j]);
            }
        }
        return len;
    }
};
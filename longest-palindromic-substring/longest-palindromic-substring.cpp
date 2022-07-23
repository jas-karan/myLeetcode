class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        
        string ans;
        int length=0;
        
        vector<vector<bool>>memo(n,vector<bool>(n,false));
        
        for(int len=0;len<n;len++){
            for(int i=0,j=len;j<n;i++,j++){
                if(len==0){
                    memo[i][j]=true;
                }
                else if(len==1){
                    memo[i][j] = s[i]==s[j];
                }
                else{
                    memo[i][j] = (s[i]==s[j]) && memo[i+1][j-1];
                }
                
                if(memo[i][j]){
                    if(j-i+1>length){
                        length=j-i+1;
                        ans=s.substr(i,length);
                    }
                }
            }
        }
        
        
        return ans;
    }
};
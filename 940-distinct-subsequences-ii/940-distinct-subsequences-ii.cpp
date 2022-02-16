class Solution {
public:
    int MOD = 1e9+7;
    
    int distinctSubseqII(string s) {
        //how many substrings of string of length n are possible?
        //length 0 + length 1 +... + length n
        //1 + (n-1+1) + (n-2+1) + ... + (1) (has to be contiguous)
        //1 + (n) + (n-1) + ... + (1)
        //1 + n*(n+1)/2   
        //non empty -  n*(n+1)/2
        
        //how many subsequences of sequence of length n are possible?
        //length 0 + length 1 +... + length n
        //nC0 + nC1 + nC2 +..+ nCn = 2^n  (we can choose any chars)
        //non empty - 2^n-1 
        
        //2 is getting multipied after every char
        //for string "aba"
        // a  b  c  a
        // for first char a - we have 2 sequences "" and "a"
        // now for second char b - b can get add to these last subsequences or not
        // two options so 2*(last #subsequence) = 4 sequences ("","b","a","ab")
        //at third char - 2*4 = 8 ("","b","a","ab","a","ba","aa","aba")
        //see that "a" is repeated so 8-1 = 7
        
        int n = s.length();
        int dp[n+1];
        
        dp[0]=1; //only ""
        
        unordered_map<char,int>map;
        
        for(int i=1;i<=n;i++){
            dp[i]=(2*dp[i-1])%MOD;
            
            //remove duplicates
            if(map.find(s[i-1])!=map.end()){
                dp[i]=(dp[i]-dp[map[s[i-1]]-1])%MOD;
            }
            
            map[s[i-1]]=i;
        }
        dp[n]--;
        if(dp[n]<0) dp[n]+=MOD;
        return dp[n]%MOD;
        
    }
};
class Solution {
public:
    bool isMatch(string s, string p) {
        int sl = s.length();
	    int pl = p.length();
	
	    vector<vector<bool>>dp(sl+1,vector<bool>(pl+1,false));
	
	    dp[0][0] = true;
	
	    for(int j=1;j<=pl;j++){
	    	dp[0][j] = p[j-1]=='*' && dp[0][j-1];
	    }
	
	    for(int j=1;j<=pl;j++){
		    for(int i=1;i<=sl;i++){
			    if(p[j-1]==s[i-1] || p[j-1]=='?')
				    dp[i][j] = dp[i-1][j-1];
			
			    else if(p[j-1]=='*'){
				    dp[i][j] = dp[i][j-1] || dp[i-1][j];
			    }
		    }
	    }
	
	    return dp[sl][pl];
    }
};
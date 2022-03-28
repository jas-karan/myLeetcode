class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>>dp(s.length()+1,vector<bool>(p.length()+1,false));
	
	    dp[0][0] = true;
	    //if both are empty
	
	    //dp[i][0] for i>0 remains false as pattern is empty but s is non empty
	
	    //first row - s is empty and pattern non empty
	    //dp[0][j] is true if p[j-1] is '*' and dp[0][j-2] is true
	    //basically if pattern is 'a*' or 'a*c*b*' any combo
	    //dp[0][1] will be false (obviously)
	
	    for(int j=2;j<=p.length();j++){
	    	dp[0][j] = (p[j-1]=='*') && dp[0][j-2];
	    }
	
	    //fix p(0,j) and iterate s
	
	    for(int j=1;j<=p.length();j++){
		    for(int i=1;i<=s.length();i++){
			    //either chars are equal or it could be any char
			    if(p[j-1]==s[i-1] || p[j-1]=='.') 
				    dp[i][j] = dp[i-1][j-1];
			
			    //else if pattern char is '*'
			    else if(p[j-1]=='*'){
				    //then it can either act as 0 number of char preceding *
				    //in that case it will be dp[i][j-2]
				
				    //or current char of string equals the char preceding * 
				    //the result is dp[i-1][j]
				
				    dp[i][j] = dp[i][j-2] || ((s[i-1]==p[j-2] || p[j-2]=='.') && dp[i-1][j]);
				
			    }
		    }
	    }
	
	
	    return dp[s.length()][p.length()];
    }
};
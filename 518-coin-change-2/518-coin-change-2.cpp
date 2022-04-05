class Solution {
public:
    int change(int target, vector<int>& coins) {
        int c = coins.size();
	
	    vector<vector<int>>dp(c+1,vector<int>(target+1,0));
	
	    for(int i=0;i<=target;i++) dp[0][i]=0;
	    for(int i=1;i<=c;i++) dp[i][0]=1;
	
	    for(int i=1;i<=c;i++){
		    for(int j=1;j<=target;j++){
			    if(j>=coins[i-1]){
				    dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
			    }
		    	else dp[i][j]=dp[i-1][j];
		    }
	    }
	
	    return dp[c][target];
    }
};
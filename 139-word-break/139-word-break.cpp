class Solution {
public:
    bool wordBreak(string s, vector<string>& w) {
        unordered_set<string>set;
	    for(string s:w) set.insert(s);
	
// 	int i=0,j=0;
// 	for(j=0;j<s.length();j++){
// 		string curr = s.substr(i,j-i+1);
// 		if(set.find(curr)!=set.end() && wordBreak(s.substr(j+1),w)){
			
// 			i=j+1;
// 		}
// 	}
	
// 	if(i==s.length()) return true;
// 	return false;
	
	    vector<bool>dp(s.length()+1,false);
	    dp[0]=true;
	
	    for(int i=1;i<=s.length();i++){
		    for(int j=i-1;j>=0;j--){
                if(dp[j] && set.find(s.substr(j,i-j))!=set.end()){
                    dp[i]=true;
				    break;
			    }
		    }
	    }
	
	    return dp[s.length()];
    }
};
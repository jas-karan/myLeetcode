class Solution {
public:
    bool ispal(string s,int i,int j){
	    while(i<=j){
		    if(s[i]!=s[j]) return false;
		    i++;j--;
	    }
	    return true;
    }

    void call(string s,int ind,vector<string>&curr,vector<vector<string>>&ans){
	    if(ind>=s.length()){
	    	ans.push_back(curr);
	    	return;
	    }
	
	    for(int i=ind;i<s.length();i++){
		    if(ispal(s,ind,i)){
			    curr.push_back(s.substr(ind,i-ind+1));
			    call(s,i+1,curr,ans);
			    curr.pop_back();
		    }
	    }
	
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
	    vector<string>curr;
	
	    call(s,0,curr,ans);
	    return ans;
        
    }
};
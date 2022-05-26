class Solution {
public:
    unordered_set<string>dict;
    
//     void helper(vector<string>&res, string curr, string s){
//         if(s.length()==0){
//             curr.pop_back();  //last space removal
//             res.push_back(curr);
//             return;
//         }
//         string temp = "";
//         for(int i=0;i<s.length();i++){
//             temp+=s[i];
//             if(dict.find(temp) != dict.end()){
//                 helper(res,curr+temp+" ",s.substr(i+1));
//             }
//         }
        
//     }
    
    //word break 1
    bool canBreak(string s){
        int n = s.length();
        
        vector<bool>dp(n+1,false);
        
        dp[0] = true; //an empty string can be made
        
        for(int i=1;i<=n;i++){
            
            for(int j=i-1;j>=0;j--){
                
                string temp = s.substr(j,i-j);  
                
                if(dict.find(temp)!=dict.end())  //if from jth index is in dict
                    dp[i] = dp[i]||dp[j];   //and till j-1 th index is breakable
                
                if(dp[i]) break;  //till i-1 th index is breakable
            }
        }
        
        return dp[n];
    }
    
    //word break 2
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // vector<string>res;
        // string curr="";
        
        for(string w:wordDict) dict.insert(w);
        
        // helper(res,curr,s);
        
        if(!canBreak(s)) return {}; 
        
        int n = s.length();
        vector<vector<string>>dp(n+1);
        
        dp[0].emplace_back("");
        
        for(int i=1;i<=n;i++){
            
            for(int j=i-1;j>=0;j--){
                
                string temp = s.substr(j,i-j);
                
                if(dict.find(temp)!=dict.end()){
                    for(string t:dp[j]){
                        if(j==0) dp[i].push_back(temp);
                        else dp[i].push_back(t+" "+temp);
                    }
                }
            }
        }
        
        return dp[n];
    }
};
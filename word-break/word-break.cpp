class Solution {
public:
    unordered_set<string>dict;
    
    bool wordBreak(string s, vector<string>& w) {
        int n = s.length();
        
        for(string s:w) dict.insert(s);
        
        vector<bool>memo(n+1,false);
        memo[0] = true;
        
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                string curr = s.substr(j,i-j);
                if(dict.find(curr)!=dict.end()){
                    memo[i] = memo[i] || memo[j];
                }
                if(memo[i]) break;
            }
        }
        
        return memo[n];
    }
};
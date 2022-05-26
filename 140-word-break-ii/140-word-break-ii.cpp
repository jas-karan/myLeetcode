class Solution {
public:
    unordered_set<string>dict;
    
    void helper(vector<string>&res, string curr, string s){
        if(s.length()==0){
            res.push_back(curr);
            return;
        }
        
        for(int i=0;i<s.length();i++){
            if(dict.find(s.substr(0,i+1)) != dict.end()){
                helper(res,curr+s.substr(0,i+1)+" ",s.substr(i+1));
            }
        }
        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>res;
        string curr="";
        
        for(string w:wordDict) dict.insert(w);
        
        helper(res,curr,s);
        
        for(string&w:res) w=w.substr(0,w.length()-1);
        return res;
    }
};
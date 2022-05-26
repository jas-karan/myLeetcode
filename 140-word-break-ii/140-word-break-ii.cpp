class Solution {
public:
    unordered_set<string>dict;
    
    void helper(vector<string>&res, string curr, string s){
        if(s.length()==0){
            curr.pop_back();  //last space removal
            res.push_back(curr);
            return;
        }
        string temp = "";
        for(int i=0;i<s.length();i++){
            temp+=s[i];
            if(dict.find(temp) != dict.end()){
                helper(res,curr+temp+" ",s.substr(i+1));
            }
        }
        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>res;
        string curr="";
        
        for(string w:wordDict) dict.insert(w);
        
        helper(res,curr,s);
        
        return res;
    }
};
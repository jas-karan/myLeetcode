class Solution {
public:
    bool check(string s,int i,int j){
        while(i<j) if(s[i++]!=s[j--]) return false;
        return true;
    }
    
    void dfs(string s,int ind,vector<string>&cur, vector<vector<string>>&res){
        if(ind>=s.length()){
            res.push_back(cur);
            return;
        }
        
        for(int i=ind;i<s.length();i++){
            if(check(s,ind,i)){
                cur.push_back(s.substr(ind,i-ind+1));
                dfs(s,i+1,cur,res);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>cur;
        
        dfs(s,0,cur,res);
        
        return res;
    }
};
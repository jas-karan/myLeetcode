class Solution {
public:
    bool check(string s,int i,int j){
        while(i<j) if(s[i++]!=s[j--]) return false;
        return true;
    }
    
    void dfs(string s,int ind,vector<string>&cur, vector<vector<string>>&res,vector<vector<bool>>&mem){
        if(ind>=s.length()){
            res.push_back(cur);
            return;
        }
        
        for(int i=ind;i<s.length();i++){
            if(s[i]==s[ind]&& (i-ind+1<=2 || mem[ind+1][i-1])){
                mem[ind][i]=true;
                cur.push_back(s.substr(ind,i-ind+1));
                dfs(s,i+1,cur,res,mem);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<bool>>mem(s.length(),vector<bool>(s.length(),false));
        vector<vector<string>>res;
        vector<string>cur;
        
        dfs(s,0,cur,res,mem);
        
        return res;
    }
};
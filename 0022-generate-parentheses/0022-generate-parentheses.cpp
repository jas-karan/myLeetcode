class Solution {
public:
    void dfs(int o,int c,string s,vector<string>&res){
        if(o==0 && c==0){
            res.push_back(s);
            return;
        }
        
        if(o) dfs(o-1,c+1,s+"(",res);
        if(c) dfs(o,c-1,s+")",res);
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        dfs(n,0,"",res);
        return res;
    }
};
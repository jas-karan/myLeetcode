class Solution {
public:
    vector<string>res;
    
    void dfs(int o,int c,string curr){
        if(o==0 && c==0){
            res.push_back(curr);
            return;
        }
        
        if(o!=0) dfs(o-1,c+1,curr+"(");
        if(c!=0) dfs(o,c-1,curr+")");
    }
    
    vector<string> generateParenthesis(int n) {
        dfs(n,0,"");
        return res;
    }
};
class Solution {
public:
    unordered_map<char,vector<char>>mp;
    
    void dfs(string d,int ind,string cur,vector<string>&ans){
        if(ind==d.length()){
            ans.push_back(cur);
            return;
        }
        
        for(auto m:mp[d[ind]]){
            dfs(d,ind+1,cur+m,ans);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
        vector<string>ans;
        dfs(digits,0,"",ans);
        return ans;
    }
};
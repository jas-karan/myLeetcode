class Solution {
public:
    unordered_set<string>map;
    
//     bool canBreak(string w,int ind){
//         if(ind==w.length()) return true;
    
//         string curr = "";
//         for(int i=ind;i<w.length();i++){
//             curr+=w[i];
//             if(map.find(curr)!=map.end()){
//                 if(ind==0 && i==w.length()-1) return false;
//                 if(canBreak(w,i+1)) return true;
//             }
//         }
        
//         return false;
//     }
    
    bool canBreak(string w){
        int n = w.length();
        
        vector<bool>dp(n+1,false);
        dp[0]=true;
        
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(map.find(w.substr(j,i-j))!=map.end()){
                    dp[i] = dp[i]||dp[j];
                }
                if(dp[i]) break;
            }
        }
        
        return dp[n];
    }
    
    
    static bool comp(string a, string b){
        return a.length()<b.length();
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // for(string w:words){
        //     map.insert(w);
        // }
        
        vector<string>res;
        
        sort(words.begin(), words.end(), comp);
        
        for(string w:words){
            if(w.length()>0 && canBreak(w)){
                res.push_back(w);
            }
            map.insert(w);
        }
        
        return res;
    }
};
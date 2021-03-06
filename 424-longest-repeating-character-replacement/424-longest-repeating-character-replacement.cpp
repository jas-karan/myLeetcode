class Solution {
public:
    //in any window, there will be max freq char and other k chars
    int characterReplacement(string s, int k) {
        int n = s.length();
        
        int l=0,r=0,res=0,maxcnt=0;
        unordered_map<int,int>map;
        
        while(r<n){
            map[s[r]]++;
            maxcnt=max(maxcnt,map[s[r]]);
            
            while(r-l+1>k+maxcnt){
                map[s[l]]--;
                l++;
            }
            
            res=max(res,r-l+1);
            r++;
        }
        
        return res;
    }
};
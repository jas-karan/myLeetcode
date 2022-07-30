class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int ans=0;
        
        unordered_map<int,int>ind;
        int l=0,r=0;
        while(r<n){
            if(ind.count(s[r])){
                l=max(l,ind[s[r]]+1);
            }
            ind[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
        }
        
        return ans;
    }
};
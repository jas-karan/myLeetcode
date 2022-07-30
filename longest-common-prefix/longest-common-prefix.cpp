class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==1) return strs[0];
        
        sort(begin(strs),end(strs));
        
        string ans="";
        for(int i=0;i<min(strs[0].length(),strs[n-1].length());i++){
            if(strs[0][i]!=strs[n-1][i]) break;
            ans+=strs[0][i];
        }
        
        return ans;
    }
};
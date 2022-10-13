class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        string t = s;
        reverse(begin(t),end(t));
        
        string m = s+'*'+t;
        vector<int>lps(m.length(),0);
        
        for(int i=1;i<m.length();i++){
            int j = lps[i-1];
            while(j>0 && m[i]!=m[j]) j=lps[j-1];
            if(m[i]==m[j]) j++;
            lps[i] = j;
        }
        
        return t.substr(0,n-lps[m.length()-1])+s;
    }
};
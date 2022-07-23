class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        string t="";
        
        for(int i=0;i<n;i++){
            if(isalpha(s[i])) t+=tolower(s[i]);
            else if(s[i]>='0'&&s[i]<='9') t+=s[i];
        }
        n=t.length();
        
        for(int i=0,j=n-1;i<n,j>=0;i++,j--) if(t[i]!=t[j]) return false;
        
        return true;
    }
};
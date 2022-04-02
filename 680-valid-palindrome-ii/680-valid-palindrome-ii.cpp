class Solution {
public:
    bool call(string s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        int i=0,j=s.length()-1;
        bool flag = 0;
        while(i<=j){
            if(s[i]!=s[j]){
                return call(s,i,j-1)||call(s,i+1,j);
            }
            i++;j--;
        }
        return true;
        
    }
};
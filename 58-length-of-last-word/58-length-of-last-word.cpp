class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.length()-1;
        while(s[i]==' ') i--;
        while(i>=0 && s[i]!=' '){
            i--;
            length++;
        }
        
        return length;
    }
};
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1="",t1="";
        int hashes=0;
        
        int i=s.length()-1;
        while(i>=0){
            if(s[i]=='#') hashes++;
            else{
                if(hashes){
                    hashes--;
                }
                else{
                    s1=s[i]+s1;
                }
            }
            i--;
        }
        
        i=t.length()-1;
        hashes=0;
        while(i>=0){
            if(t[i]=='#') hashes++;
            else{
                if(hashes){
                    hashes--;
                }
                else{
                    t1=t[i]+t1;
                }
            }
            i--;
        }
        
        return s1==t1;
    }
};
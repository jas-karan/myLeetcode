class Solution {
public:
    string decodeString(string s) {
        int i=0;
        string ans="";
        
        while(i<s.length()){
            if(isalpha(s[i])){
                ans+=s[i];
                i++;
                continue;
            }
            else{
                int t=0;
                while(s[i]!='['){
                    t=t*10+(s[i]-'0');
                    i++;
                }
                string inside = "";
                i++;
                int open=0;
                while(!(s[i]==']'&&open==0)){
                    if(s[i]=='['){
                        open++;
                    }
                    if(s[i]==']'){
                        open--;
                    }
                    inside+=s[i];
                    i++;
                }
                i++;
                inside = decodeString(inside);
                while(t--){
                    ans+=inside;
                }
            }
        }
        
        return ans;
    }
};
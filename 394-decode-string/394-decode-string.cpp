class Solution {
public:
    string decode(string s,int &i){
        string ans="";
        
        while(i<s.length() && s[i]!=']'){
            if(isalpha(s[i])){
                ans+=s[i];
                i++;
            }
            else{
                int t=0;
                while(s[i]!='['){
                    t=t*10+(s[i]-'0');
                    i++;
                }
                i++; //'['
                string inside = decode(s,i);
                i++; //']'
                
                while(t--){
                    ans+=inside;
                }
            }
        }
        
        return ans;
    }
    
    string decodeString(string s) {
        int i=0;
        s = decode(s,i);
        return s;
    }
};
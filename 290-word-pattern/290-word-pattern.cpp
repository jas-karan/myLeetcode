class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;
        int i=0;
        int j=0;
        while(i<pattern.length() && j<s.length()){
            char ch=pattern[i++];
            string str = "";
            while(j<s.length() && s[j]!=' '){
                str+=s[j++];
            }
            
            if(mp1.find(ch)==mp1.end() && mp2.find(str)==mp2.end()){
                mp1[ch]=str;
                mp2[str]=ch;
            }
            else{
                if(mp1.find(ch)!=mp1.end() && str!=mp1[ch]) return false;
                else if(ch!=mp2[str]) return false;
            }
            j++;
        }
        cout<<i<<" "<<j<<endl;
        if(i!=pattern.length() || j!=s.length()+1) return false;
        return true;
    }
};
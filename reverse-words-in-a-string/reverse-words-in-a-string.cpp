class Solution {
public:
    void rev(string&s,int i,int j){
        while(i<j) swap(s[i++],s[j--]);
    }
    string reverseWords(string s) {
        int i=0,j=0;
        int cnt=0;
        
        while(i<s.length()){
            while(i<s.length() && s[i]==' ') i++;
            if(i==s.length()) break;
            if(cnt) s[j++]=' ';
            int start=j;
            while(i<s.length() && s[i]!=' '){
                s[j]=s[i];
                i++;j++;
            }
            cnt++;
            rev(s,start,j-1);
            
        }
        
        s.resize(j);
        reverse(begin(s),end(s));
        return s;
    }
};
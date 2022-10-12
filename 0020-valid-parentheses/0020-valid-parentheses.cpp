class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char>st;
        unordered_map<char,char>mp;
        mp[']']='['; mp['}']='{'; mp[')']='(';
        
        for(char c:s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
                continue;
            }
            if(st.empty() || st.top()!=mp[c]) return false;
            st.pop();
        }
        
        return st.empty();
    }
};
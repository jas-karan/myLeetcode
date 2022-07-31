class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        
        if(n<=k) return "0";
        
        stack<char>st;
        
        for(int i=0;i<n;i++){
            while(k && st.size()>0 && st.top()>num[i]){ st.pop(); k--;}
            st.push(num[i]);
        }
        
        while(k && st.size()){st.pop(); k--;}
        
        string s = "";
        
        while(st.size()){
            s.push_back(st.top());
            st.pop();
        }
        
        int i=s.length()-1;
        while(i>=0 && s[i]=='0'){
            s.pop_back();
            i--;
        }
        
        reverse(begin(s),end(s));
        return s==""?"0":s;
    }
};
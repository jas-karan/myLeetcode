class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<int>st;
        
        for(char c:s){
            if(c=='{'||c=='['||c=='(') st.push(c);
            else if(st.empty()) return false;
            else{
                if(c==']' && st.top()!='[') return false;
                if(c=='}' && st.top()!='{') return false;
                if(c==')' && st.top()!='(') return false;
                st.pop();
            }
        }
        
        return st.empty();
    }
};
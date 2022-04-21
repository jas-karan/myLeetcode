class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        
        stack<int>ind;
        
        int l=-1;
        int res=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') ind.push(i);
            
            else{
                if(ind.empty()){
                    l=i; continue;
                }
                
                ind.pop();
                if(ind.empty()) res=max(res,i-l);
                else res=max(res,i-ind.top());
            }
        }
        
        return res;
    }
};
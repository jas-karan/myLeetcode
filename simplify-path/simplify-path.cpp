class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        int n = path.length();
        
        int i=0;
        while(i<n){
            if(path[i]=='/'){
                i++;
                continue;
            }
            string t="";
            while(i<n && path[i]!='/'){
                t+=path[i];
                i++;
            }
            if(t=="."){
                continue;
            }
            else if(t==".."){
                if(st.size()) st.pop();
            }
            else st.push(t);
        }
        
        string res="";
        while(!st.empty()){
            res="/"+st.top()+res;
            st.pop();
        }
        
        if(res.size()==0) return "/";
        return res;
    }
};
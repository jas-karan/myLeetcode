class Solution {
public:
    bool check(string s){
        int close = 0;
        for(char c:s){
            if(c=='(') close++;
            else if(c==')' && close) close--;
            else if(c==')') return false;
        }
        return close==0;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string>ans;
        unordered_set<string>vis;
        queue<string>q;
        q.push(s);
        vis.insert(s);
        bool f=false;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string t = q.front(); q.pop();
                if(check(t)){
                    ans.push_back(t);
                    f=true;
                }
                if(f) continue;
                for(int i=0;i<t.length();i++){
                    if(t[i]=='(' || t[i]==')'){
                        string x = t.substr(0,i);
                        string y = t.substr(i+1);

                        if(vis.find(x+y)==vis.end()){
                            q.push(x+y);
                            vis.insert(x+y);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
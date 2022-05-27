class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int>res;
        stack<int>st;
        int n = a.size();
        
        for(int i=0;i<n;i++){
            bool flag = false;
            
            while(!st.empty() && (st.top()>0 && a[i]<0)){
                if(abs(st.top())==abs(a[i])){
                    st.pop();
                    flag=true;
                    break;
                }
                else if(abs(st.top())<abs(a[i])){
                    st.pop();
                }
                else{
                    flag = true;
                    break;
                }
            }
            
            if(!flag) st.push(a[i]);
        }
        
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};
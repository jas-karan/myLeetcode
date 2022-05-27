class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        
        stack<int>st;
        int n = a.size();
        
        for(int i=0;i<n;i++){
            
            while(!st.empty() && (st.top()>0 && a[i]<0) && abs(st.top())<abs(a[i])){
                st.pop();
            }
            
            if(!st.empty() && (st.top()>0 && a[i]<0) && abs(st.top())==abs(a[i])){
                st.pop();
            }
            
            else if(st.empty() || !(st.top()>0 && a[i]<0)){
                st.push(a[i]);
            }
            
        }
        
        vector<int>res(st.size());
        
        for(int i=st.size()-1;i>=0;i--){
            res[i]=st.top();
            st.pop();
        }
        
        return res;
    }
};
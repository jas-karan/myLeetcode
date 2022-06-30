class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        
        int n = cars.size();
        vector<double>ans(n); 
        
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            //remove high speed cars
            while(st.size() && cars[st.top()].back()>=cars[i].back()) st.pop();
            
            double time=-1;
            
            //find the next car that curr car will collide with
            while(st.size()){
                double d = 1.0 * (cars[st.top()][0]-cars[i][0]);
                double v = 1.0 * (cars[i][1]-cars[st.top()][1]);
                time = d/v;
                
                if(ans[st.top()]==-1 || time <= ans[st.top()]) break;
                
                st.pop();
            }
            
            ans[i]=time;
            st.push(i);
        }
        
        return ans;
        
    }
};
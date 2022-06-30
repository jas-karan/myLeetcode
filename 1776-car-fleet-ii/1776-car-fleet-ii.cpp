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
                
                //in stack ,speed will be in decreasing order,
                //if time is > then top then curr car should collide with top's fleet
                //which will be of slower speed
                //but if time is < then we break or no fleet of top 
                if(ans[st.top()]==-1 || time <= ans[st.top()]) break;
                
                st.pop();
            }
            
            ans[i]=time;
            st.push(i);
        }
        
        return ans;
        
    }
};
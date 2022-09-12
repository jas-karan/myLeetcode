class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& I) {
        int n = I.size();
        sort(begin(I),end(I));
        auto prev = I[0];
        
        vector<vector<int>>ans;
        
        for(int i=1;i<n;i++){
            if(I[i][0]<=prev[1]){
                prev[1] = max(prev[1], I[i][1]);
            }
            else{
                ans.push_back(prev);
                prev = I[i];
            }
        }
        ans.push_back(prev);
        
        return ans;
    }
};
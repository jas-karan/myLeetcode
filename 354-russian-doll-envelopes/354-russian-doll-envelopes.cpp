class Solution {
public:
    int ceil(vector<int>sorted,int x){
        int index;
        int l=0,r=sorted.size()-1;
        
        while(l<=r){
            int mid = l+(r-l)/2;
            
            if(sorted[mid]<x) l=mid+1;
            else{
                index=mid;
                r=mid-1;
            }
        }
        
        return index;
    }
    
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        // sort(envelopes.begin(), envelopes.end());
        
        int n = envelopes.size();
        
//         vector<int>dp(n,1);
//         int maxEnvelopes=1;
        
//         for(int i=0;i<n;i++){
//             for(int j=i-1;j>=0;j--){
//                 if(envelopes[j][1]<envelopes[i][1] && envelopes[j][0]<envelopes[i][0]){
//                     dp[i] = max(dp[i],1+dp[j]);
//                 }
//             }
//             maxEnvelopes = max(maxEnvelopes,dp[i]);
//         }
        
//         return maxEnvelopes;
        
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) 
             -> bool {return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];});
        
        vector<int>sorted;
        sorted.push_back(envelopes[0][1]);
        
        for(int i=1;i<n;i++){
            int h = envelopes[i][1];
            
            if(sorted[sorted.size()-1]<h){
                sorted.push_back(h);
            }
            else{
                int c = ceil(sorted,h);
                sorted[c] = h;
            }
        }
        
        return sorted.size();
        
    }
};
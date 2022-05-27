class Solution {
public:
    int dp[2001][2001] = {} , mx_val = 2001;
    
    int solve(vector<int>&a,vector<int>&b,int i,int prev)
    {
        if(i >= a.size())
            return 0;
         
        // take the index of element in array b which is greater than prev
        int j = upper_bound(b.begin() , b.end() , prev) - b.begin();
        
        
        
        if(dp[i][j] == 0){
             dp[i][j] = j < b.size() ? 1 + solve(a,b,i+1,b[j]):mx_val ;
            // if prev elemnt of array a is smaller than next than no need of conversion
            
            if(prev < a[i])
                dp[i][j] = min(dp[i][j] , solve(a,b,i+1,a[i]));
        } 
        
        
        
        return dp[i][j];
    }
    int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        
        // sort the second aray in order to start with the smallest element
        sort(b.begin() , b.end());
        int p = solve(a,b,0,-1e9);
        return p >= mx_val ? -1 : p;
    }
};
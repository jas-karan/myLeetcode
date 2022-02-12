class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //which balloon should burst last?
        //3158: if 3 then you get (1*3*1)+rec(158)
        //if 1 then rec(3)+(1*1*1)+rec(58) and so on  
        
        //l+r+nums[i] 
        
        //store rec values in dp
        //dp[i][j] = max val for bursting balloons from i to j (inclusive)
        
        //dp[i][i] = nums[i-1]*nums[i]*nums[i+1] 
        
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int g=0;g<n;g++){  //diagonally upwards
            
            for(int i=0,j=g; j<n; i++,j++){  //traverse diagonal
                
                int maxVal = INT_MIN;
                //which balloon from i to j to burst last
                for(int k=i;k<=j;k++){
                    
                    int l = (k==0) ? 0 : dp[i][k-1];
                    int r = (k==j) ? 0 : dp[k+1][j];
                    
                    //kth balloon to be burst last
                    //which means i to k-1 and k+1 to j are already bursted
                    
                    int val = (i==0 ? 1:nums[i-1])*nums[k]*(j==n-1 ? 1 : nums[j+1]);
                    
                    int total = l + r + val;
                    maxVal = max(maxVal,total);
                }
                
                dp[i][j] = maxVal;
            }
        }
        
        return dp[0][n-1];
    }
};
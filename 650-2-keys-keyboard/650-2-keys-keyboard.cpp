class Solution {
public:
//     int helper(int present,int copied,int n){
//         if(present>n) return INT_MAX;  //wrong operations
//         if(present==n) return 0;  //exactly n are required
        
//         int copy_paste = helper(present+present,present,n);
//         if(copy_paste!=INT_MAX) copy_paste+=2;   ///overflow
        
//         int paste = helper(present+copied,copied,n);
//         if(paste!=INT_MAX) paste+=1;
        
//         return min(copy_paste,paste);
//     }
    
    int helper(int present,int copied,int n,vector<vector<int>>&dp){
        if(present>n) return INT_MAX;  //wrong operations
        if(present==n) return 0;  //exactly n are required
        
        if(dp[present][copied]!=-1) return dp[present][copied];
        
        int copy_paste = helper(present+present,present,n,dp);
        if(copy_paste!=INT_MAX) copy_paste+=2;   ///overflow
        
        int paste = helper(present+copied,copied,n,dp);
        if(paste!=INT_MAX) paste+=1;
        
        return dp[present][copied]=min(copy_paste,paste);
    }
    
    int minSteps(int n) {
//         //we cannot copy only!! it will be infinite loop then,,keep copying...
        
//         if(n<2) return 0;
//         return 1+helper(1,1,n);   //initially ,first op can be copy only
        
        //we can store overlapping subproblems
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        if(n<2) return 0;
        return 1+helper(1,1,n,dp);
    }
};
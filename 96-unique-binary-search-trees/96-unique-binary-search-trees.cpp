class Solution {
public:
    int numTrees(int n) {
        //take every node from 1 to n as root
        //then depending on root, some numbers can be only on left and some on right
        //the numbers on left and right can also be arranged in different structures
        //that is numTrees(#leftnodes) + numTress(#rightNodes)
        //so we also need these, store in dp
        //eg. for n=4, (#leftNodes,#rightNodes) -
        //(1,2),(2,1),(0,3),(3,0)
        //which is nothing but catalan number Cn = C0*Cn-1 + C1*Cn-2 + ....
        
        if(n<2) return 1;
        
        vector<int>dp(n+1,0);
        dp[0]=dp[1]=1;
        
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]+=(dp[j]*dp[i-j-1]);
            }
        }
        
        
        return dp[n];
    }
};
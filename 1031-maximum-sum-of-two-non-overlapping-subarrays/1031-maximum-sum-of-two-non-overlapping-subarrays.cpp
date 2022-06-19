class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int l, int m) {
        int n = nums.size();
        vector<int>pre(n+1,0);
        for(int i=1;i<=n;i++){
            pre[i] = pre[i-1]+nums[i-1];
        }
        
        int ans = 0;
        //selecting the l length subarray
	    for(int i = 0; i<=n-l; i++) {
		    int lsum = pre[i+l] - pre[i];
		
		    //looking left
		    for(int j = 0; j<=i-m; j++) {
			    int msum = pre[j+m] - pre[j];
			    ans = max(ans, lsum + msum);
		    }
		
		    //looking right 
		    for(int j = i+l; j<=n-m; j++) {
			    int msum = pre[j+m] - pre[j];
			    ans = max(ans, lsum + msum);
		    }
	    }
	    return ans;
    }
};
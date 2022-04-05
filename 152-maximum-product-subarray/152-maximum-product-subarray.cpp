class Solution {
public:
    int maxProduct(vector<int>& A) {
        
        int maxEnd = A[0],minEnd = A[0];
        //we also maintain minEnding (largest negative product)
	    //so if negative element comes, minEnd*ele can become maximum
	    int ans = A[0];
	
	    for(int i=1;i<A.size();i++){
		
		    int currmax = max({A[i],maxEnd*A[i],minEnd*A[i]});
		    minEnd = min({A[i],maxEnd*A[i],minEnd*A[i]});
		    maxEnd = currmax;
		
		    ans = max(ans,maxEnd);
	    }
	
	    return ans;
    }
};
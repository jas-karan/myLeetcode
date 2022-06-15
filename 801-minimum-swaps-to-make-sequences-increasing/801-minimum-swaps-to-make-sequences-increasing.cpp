class Solution {
public:
//     vector<vector<int>> dp;
    
//     int solve(vector<int> &num1,vector<int> &num2,int i,int prev1,int prev2,bool swaped){
//         int n = num1.size();
//         if(i == n){
//             return 0;
//         }
        
//         if(dp[i][swaped] != -1){
//             return dp[i][swaped];
//         }
        
//         int noSwap=1e9;
//         if(num1[i]>prev1 && num2[i]>prev2){
//             noSwap = solve(num1,num2,i+1,num1[i],num2[i],false);
//         }
        
//         int swap=1e9;
//         if(num1[i]>prev2 && num2[i]>prev1){
//             swap = 1 + solve(num1,num2,i+1,num2[i],num1[i],true);
//         }
        
//         return dp[i][swaped] = min(swap,noSwap);
//     }
    
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
//         int n=nums1.size();
//         dp.resize(n+1,vector<int> (2,-1));
        
//         return solve(nums1,nums2,0,-1,-1,0);
        
        int n=nums1.size();
	vector<int> swap(n, INT_MAX), keep(n, INT_MAX);

	keep[0]=0;
	swap[0]=1;

	for(int i=1; i<n; i++) {
		if(nums1[i]>nums1[i-1] && nums2[i]>nums2[i-1]) {
			keep[i]=keep[i-1];
			swap[i]=swap[i-1]+1;
		} 
		if(nums1[i]>nums2[i-1] && nums2[i]>nums1[i-1]) {
			keep[i]=min(swap[i-1],keep[i]);
			swap[i]=min(keep[i-1]+1,swap[i]);
		}
	}

	return min(keep[n-1],swap[n-1]);
    }
};
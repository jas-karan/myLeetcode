class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        if(n<=2) return 0;
        
        int lmax = INT_MIN,rmax = INT_MIN;
        
        int l=0,r=n-1;
        int water=0;
        while(l<=r){
            lmax = max(lmax,height[l]);
            rmax = max(rmax,height[r]);
            
            if(height[l]<height[r]){
                water+=(min(lmax,rmax)-height[l]);
                l++;
            }
            else{
                water+=(min(lmax,rmax)-height[r]);
                r--;
            }
        }
        
        return water;
    }
};
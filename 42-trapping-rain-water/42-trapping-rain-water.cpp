class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2) return 0;
        
        int lmax[n],rmax[n];
        
        int l = height[0];
        for(int i=1;i<n;i++){
            lmax[i]=l;
            l=max(l,height[i]);
        }
        
        int r = height[n-1];
        for(int i=n-2;i>=0;i--){
            rmax[i]=r;
            r=max(r,height[i]);
        }
        
        int water = 0;
        for(int i=1;i<n-1;i++){
            int currWater = (min(lmax[i],rmax[i])-height[i]);
            water+= currWater>0 ? currWater:0;
        }
        
        return water;
    }
};
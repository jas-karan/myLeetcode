class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0,r=n-1;
        
        int ans=0;
        while(l<r){
            ans=max(ans,min(height[l],height[r])*(r-l));
            if(height[l]<=height[r]){
                int h = height[l];
                while(l<r && height[l]<=h) l++;
            }
            else{
                int h = height[r];
                while(l<r && height[r]<=h) r--;
            }
        }
        
        return ans;
    }
};
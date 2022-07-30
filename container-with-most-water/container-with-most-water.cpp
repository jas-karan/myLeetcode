class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        
        int ans=0;
        int l=0,r=n-1;
        
        while(l<r){
            int lh = heights[l];
            int rh = heights[r];
            
            ans=max(ans,min(lh,rh)*(r-l));
            
            if(lh<rh){
                while(l<r && heights[l]<=lh) l++;
            }
            else{
                while(l<r && heights[r]<=rh) r--;
            }
        }
        
        return ans;
    }
};
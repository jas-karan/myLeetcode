class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int water = 0;
        int l = 1, r = n-2;
        int lmax = h[0], rmax = h[n-1];
        while(l<=r){
            int lh = h[l];
            int rh = h[r];
            
            lmax = max(lmax,h[l]);
            rmax = max(rmax,h[r]);
            
            if(lmax<=rmax){
                water+=(min(lmax,rmax)-lh)>0 ? (min(lmax,rmax)-lh) : 0;
                l++;
            }
            else{
                water+=(min(lmax,rmax)-rh)>0 ? (min(lmax,rmax)-rh) : 0;
                r--;
            }
            
            
        }
        
        return water;
    }
};
class Solution {
public:
    int trap(vector<int>& h) {
        //idea - keep maxleft and maxright
        //so, until curr left bar is less than maxleft, you can add curr left height to ans
        //similarly for right bars
        
        //see the fig - when left>maxl or right>maxr then we are not adding that height
        int ans = 0;
        int i=0,j=h.size()-1;
        int maxl = 0,maxr = 0;
        
        while(i<=j){
            if(h[i]<=h[j]){
                if(h[i]>=maxl) maxl=h[i];
                else ans+=(maxl-h[i]);
                i++;
            }
            else{
                if(h[j]>=maxr) maxr=h[j];
                else ans+=(maxr-h[j]);
                j--;
            }
        }
        
        return ans;
    }
};
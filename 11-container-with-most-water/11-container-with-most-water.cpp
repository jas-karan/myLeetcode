class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans = 0;
        int i=0,j=h.size()-1;
        
        while(i<j){
            int curr ;
            if(h[i]<=h[j]){
                curr = (j-i)*h[i];
                i++;
            }
            else{
                curr = (j-i)*h[j];
                j--;
            }
            ans = max(ans,curr);
        }
        
        return ans;
    }
};
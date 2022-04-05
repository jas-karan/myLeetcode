class Solution {
public:
    int maxArea(vector<int>&h) {
        //here we are finding container with max water
        //in trapping rain water, we find total water that can be collected over bars
        
        
        int ans = 0;
        int i=0,j=h.size()-1;
        
        while(i<j){
            int ht = h[i]<=h[j] ? h[i]:h[j];
            
            int curr = (j-i)*ht;
            
            while(i<j && h[i]<=ht) i++;  //move to next greater left line
            //why not smaller - (j-i) will decrease and ht will also decrease so that will not optimise
            
            while(i<j && h[j]<=ht) j--;  //move to next greatr right line
            ans = max(ans,curr);
        }
        
        return ans;
    }
};
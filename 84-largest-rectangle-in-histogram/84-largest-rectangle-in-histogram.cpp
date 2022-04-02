class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
	    int ans = 0;
	
// 	    for(int i=0;i<n;i++){
// 		    int curr = heights[i];
// 		    int j=i-1;
// 		    while(j>=0 && heights[j]>=heights[i]) j--;
// 	    	int k=i+1;
// 	    	while(k<n && heights[k]>=heights[i]) k++;
// 	    	curr+=((i-1-j)*heights[i]);
// 		    curr+=((k-i-1)*heights[i]);
//             ans = max(ans,curr);
// 	    }
// 	    return ans;
        
        //---------optimal-------
        //keep pushing increasing elements to stack
        //when a shorter element than top comes, then pop
        //why? bcoz increasing elements can be added to rectangle
        
        heights.push_back(0); //0 is added so that remaining ele in stack can be processed
        stack<int>indices;
        
        for(int i=0;i<=n;i++){
            
            //if we get lesser height then check area of previous added heights 
            while(!indices.empty() && heights[indices.top()]>heights[i]){
                int h = heights[indices.top()]; indices.pop();
                int l = indices.empty() ? -1 : indices.top();
                
                int for_curr_h = h*(i-l-1);
                ans = max(ans,for_curr_h);
            }
            //until top's height is more that ith,
            //we assign height of that top = h
            //and then left index of that top (just before)
            //note that as we are poping prev elements, i remains same
            //so range i-l-1 is increasing but h is adjusting
            
            
            //now push increasing element
            indices.push(i);
        }
        
        return ans;
    }
};
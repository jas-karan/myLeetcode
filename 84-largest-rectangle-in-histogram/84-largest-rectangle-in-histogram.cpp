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
        
        heights.push_back(0);
        stack<int>indices;
        
        for(int i=0;i<=n;i++){
            //if we get lesser height then check area of previous added heights 
            while(!indices.empty() && heights[indices.top()]>heights[i]){
                int h = heights[indices.top()]; indices.pop();
                int l = indices.empty() ? -1 : indices.top();
                
                int for_curr_h = h*(i-l-1);
                ans = max(ans,for_curr_h);
            }
            
            //now push increasing element
            indices.push(i);
        }
        
        return ans;
    }
};
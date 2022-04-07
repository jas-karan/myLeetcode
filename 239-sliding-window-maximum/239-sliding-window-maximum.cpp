class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        //deque - larger at front and smaller at back
	
	    deque<int>ind;
        for(int i=0;i<k;i++){
		
		    //remove unnecessary smaller elements
		    while(!ind.empty() && A[ind.back()]<=A[i]) ind.pop_back();
		
            ind.push_back(i);
		
        }
	
	    vector<int>ans;
	
        for(int i=k;i<A.size();i++){
            ans.push_back(A[ind.front()]);
		
            //remove out of window elements
		    while(!ind.empty() && ind.front()<=i-k) ind.pop_front();
		
		    //remove smaller elements
		    while(!ind.empty() && A[ind.back()]<=A[i]) ind.pop_back();
		
		    ind.push_back(i);
	    }
	
	    ans.push_back(A[ind.front()]);
        return ans;
    }
};
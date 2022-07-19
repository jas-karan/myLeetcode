class Solution {
public:
    vector<vector<int>> generate(int rowNo) {
        vector<vector<int>>pt(rowNo);
	
	    pt[0]={1};
	
	    for(int i=1;i<rowNo;i++){
		    pt[i].resize(i+1);
		    pt[i][0]=1;
		    pt[i][i]=1;
		
		    for(int j=1;j<i;j++){
			    pt[i][j] = pt[i-1][j]+pt[i-1][j-1];
		    }
	    }
	
    	return pt;
    }
};
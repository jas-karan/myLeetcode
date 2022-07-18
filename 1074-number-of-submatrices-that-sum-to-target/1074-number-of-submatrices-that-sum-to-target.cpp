class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
	int res = 0, m = size(A), n = size(A[0]);
        
	// calculating prefix sum for each row of matrix
	for (int row = 0; row < m; row++)
		for (int col = 1; col < n; col++)
			A[row][col] += A[row][col - 1];
        
	// calculate sum of each submatrix and check if it is equal to target
	for (int colStart = 0; colStart < n; colStart++) {
		for (int colEnd = colStart; colEnd < n; colEnd++) {
            
			for(int rowStart = 0; rowStart < m; rowStart++){
				int sum = 0;
				for(int rowEnd = rowStart; rowEnd < m; rowEnd++){
                    
					sum += A[rowEnd][colEnd] - (colStart>0 ? A[rowEnd][colStart - 1] : 0);
					if(sum == target) res++;
				}
			}
		}
	}
	return res;    
}
};
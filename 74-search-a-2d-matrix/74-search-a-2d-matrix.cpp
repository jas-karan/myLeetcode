class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int i=0;i<m;i++){
            if(matrix[i][n-1]>=target){
                for(int j=n-1;j>=0;j--){
                    if(matrix[i][j]==target) return true;
                }
                break;
            }
        }
        return false;
    }
};
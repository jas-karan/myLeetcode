class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i = 0 , j = n-1;
        while(i<m && j>=0){
            if(target==matrix[i][j]) return true;
            
            else if(target<matrix[i][j]){ //then target cannot lie below this element
                j--;                      //ie, go to left of this col
            }
            
            else i++; //target cannot lie to the left of current element, so go below
        }
        
        return false;
    }
};
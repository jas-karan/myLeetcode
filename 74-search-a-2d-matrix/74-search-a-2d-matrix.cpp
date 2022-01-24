class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        // for(int i=0;i<m;i++){
        //     if(matrix[i][n-1]>=target){
        //         for(int j=n-1;j>=0;j--){
        //             if(matrix[i][j]==target) return true;
        //         }
        //         break;
        //     }
        // }
        // return false;
        
        //ceiling using binary search
        int lo=0,hi=m-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(matrix[mid][n-1]>=target) hi=mid-1;
            else lo=mid+1;
        }
        
        int row = lo;
        if(row>m-1) row=m-1;
        lo=0,hi=n-1;
        
        //simple binary search
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid]<target) lo=mid+1;
            else hi=mid-1;
        }
        
        return false;
    }
};
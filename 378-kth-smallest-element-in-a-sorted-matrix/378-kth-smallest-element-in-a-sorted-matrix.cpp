class Solution {
public:
    int count(vector<vector<int>>& matrix, int m){
        int cnt=0;
        for(int i=0;i<matrix.size();i++){
            cnt+=(upper_bound(matrix[i].begin(),matrix[i].end(),m)-matrix[i].begin());
        }
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l=matrix[0][0],r=matrix[matrix.size()-1][matrix.size()-1];
        int ans;
        while(l<=r){
            int m=(l+r)/2;
            
            if(count(matrix,m)>=k){
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        
        return ans;
    }
};
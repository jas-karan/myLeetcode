class Solution {
public:
    //two persons from (0,0) 
    //there dist from origin remains same -> r1+c1 = r2+c2
    //if not at same position(r1!=r2 && c1!=c2), pick the cherry
    //then 4 options for (person1,person2) => (D,R),(R,D),(D,D),(R,R)
    
    int dp[51][51][51];
    
    int func(int r1 , int c1 , int r2 , int n , vector<vector<int>> &grid )
    {
        int c2=r1+c1-r2;
        
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
        {
            return INT_MIN;
        }
        
        if(dp[r1][c1][r2]!=-1)
        {
            return dp[r1][c1][r2];
        }
        
        if(r1==n-1 && c1==n-1)
        {
            return grid[r1][c1];
        }
        
        int ans=grid[r1][c1];
        
        if(r1!=r2)
        {
            ans += grid[r2][c2];
        }
        
        int temp= max(func(r1+1 , c1 , r2+1 , n , grid) , func(r1 , c1+1 , r2 , n , grid));
        temp = max(temp , func(r1+1 , c1 , r2 , n, grid));
        temp = max(temp , func(r1 , c1+1 , r2+1 , n , grid));
        
        ans+=temp;
        
        return dp[r1][c1][r2]=ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp , -1 , sizeof(dp));
        int n=grid.size();
        return max(0 , func(0,0,0,n , grid));
    }
};
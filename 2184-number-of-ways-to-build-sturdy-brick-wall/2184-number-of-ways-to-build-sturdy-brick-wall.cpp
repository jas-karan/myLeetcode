class Solution {
public:
    //first we find all the brick arrangements in single row possible
    //then we find valid arrangements of those rows
    
    int he,wi,n;
    vector<int>masks;
    int dp[101][1024];
    
    void row_dfs(int w,vector<int>&bricks,int mask){
        if(w==wi){
            masks.push_back(mask);
            return;
        }
        
        if(w>0) mask |= (1<<(w));
        
        for(int b:bricks){
            if(w+b<=wi){
                row_dfs(w+b,bricks,mask);
            }
        }
    }
    
    int col_dfs(int h,int prevmask){
        if(h==he) return 1;
        
        if(dp[h][prevmask]!=-1) return dp[h][prevmask];
        
        int ans=0;
        for(int mask:masks){
            if((prevmask&mask)==0){
                ans = (ans+col_dfs(h+1,mask))%1000000007;
            }
        }
        
        return dp[h][prevmask]=ans;
    }
    
    int buildWall(int height, int width, vector<int>& bricks) {
        he=height;
        wi=width;
        n=bricks.size();
        memset(dp,-1,sizeof(dp));
        row_dfs(0,bricks,0);
        return col_dfs(0,0);
    }
};
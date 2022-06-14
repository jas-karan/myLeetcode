class Solution {
public:
//     int dfs(string w1,string w2, int i,int j,vector<vector<int>>&mem){
//         if(i==0) return j;
//         if(j==0) return i;
        
//         if(mem[i][j]!=-1) return mem[i][j];
        
//         if(w1[i-1]==w2[j-1]) return mem[i][j] = dfs(w1,w2,i-1,j-1,mem);
        
//         return mem[i][j] = 1+min(dfs(w1,w2,i-1,j,mem), dfs(w1,w2,i,j-1,mem));
//     }
    
    int minDistance(string w1, string w2) {
        vector<vector<int>>mem(w1.size()+1,vector<int>(w2.size()+1,0));
        // return dfs(w1,w2,w1.size(),w2.size(),mem);
        
        for(int i=0;i<=w1.size();i++){
            mem[i][0] = i;
        }
        for(int j=0;j<=w2.size();j++){
            mem[0][j] = j;
        }
        
        for(int i=1;i<=w1.size();i++){
            for(int j=1;j<=w2.size();j++){
                if(w1[i-1]==w2[j-1]) mem[i][j]=mem[i-1][j-1];
                else mem[i][j] = 1+min(mem[i-1][j], mem[i][j-1]);
            }
        }
        
        return mem[w1.size()][w2.size()];
    }
};
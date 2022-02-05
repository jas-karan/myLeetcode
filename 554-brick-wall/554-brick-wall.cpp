class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        unordered_map<int,int>edge_cord;
        
        for(int i=0;i<wall.size();i++){
            int curredge = 0;
            for(int j=0;j<wall[i].size()-1;j++){
                curredge+=wall[i][j];
                edge_cord[curredge]++;
            }
        }
        
        int max_edge_cord = 0;
        
        for(auto e:edge_cord) max_edge_cord = max(max_edge_cord,e.second);
        
        return wall.size()-max_edge_cord;
    }
};
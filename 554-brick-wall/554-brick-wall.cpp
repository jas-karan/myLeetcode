class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        //basically we have to choose a coordinate which has max edges
        //for a row keep adding brick sizes to find coordinates;
        
        unordered_map<int,int>edge_cord;
        
        for(int i=0;i<wall.size();i++){
            int curredge = 0;
            
            //***** imp: dont consider last bridge ********
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
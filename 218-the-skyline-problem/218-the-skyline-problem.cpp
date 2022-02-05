class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        //idea: left walls and right walls
        //left wall => add building, right wall=> delete building
        //if height changes after adding or deleting
        //add skyline point .
        
        vector<vector<int>>ans;
        vector<vector<int>>walls;
        
        //store walls
        for(auto v:buildings){
            walls.push_back({v[0],-v[2]});  //-ve to differentiate left and right wall
            walls.push_back({v[1],v[2]});  
        }
        
        sort(walls.begin(),walls.end());//sort by x coordinates
        
        multiset<int>leftWallHeights;  //heights of current left walls
        
        leftWallHeights.insert(0);  //curr max height among left walls
        
        int curr_height = 0;
        
        for(int i=0;i<walls.size();i++){
            int x = walls[i][0];
            int h = walls[i][1];  //h or y
            
            if(h<0){  //add building if left wall
                leftWallHeights.insert(-h);
            }
            else{
                //remove building if right wall
                leftWallHeights.erase(leftWallHeights.find(h));
            }
            
            int max_height = *leftWallHeights.rbegin();
            
             //if either we go up or down
            if(curr_height!=max_height){
                
                //x remain same, h will be new height (increased or decreased)
                ans.push_back({x,max_height});
                curr_height=max_height;
            }
        }
        
        return ans;
    }
};
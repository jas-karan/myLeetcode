class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        //intuition - BFS, from start bus stop to target (level when target is found)
        //modified bfs - insert to queue all the bus stops that are reachable
        //for that I find first all the buses that shuttle thru current bus stop
        //then all the bus stops for that buses that they take me to
        //once I find some bus is taking me to target. I return the result
        
        int buses = routes.size();
        
        unordered_map<int,vector<int>>mp;
        //to store which buses shuttle the bus stop:
        for(int i=0;i<buses;i++){
            for(int j=0;j<routes[i].size();j++){
                mp[routes[i][j]].push_back(i);
            }
        }
        
        queue<int>q;
        unordered_set<int>vis_buses, vis_stops;
        
        int level = 0;
        q.push(source);
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int curr_stop = q.front(); q.pop();
                if(curr_stop==target) return level;
                
                vector<int>shuttle_buses = mp[curr_stop];
                for(int bus:shuttle_buses){
                    if(vis_buses.find(bus)!=vis_buses.end()) continue;
                    
                    vector<int>reachable_stops = routes[bus];
                    for(int stop:reachable_stops){
                        if(vis_stops.find(stop)!=vis_stops.end()) continue;
                        
                        q.push(stop);
                        vis_stops.insert(stop);
                    }
                    
                    vis_buses.insert(bus);
                }
            }
            
            level++;
        }
        
        return -1;
    }
};
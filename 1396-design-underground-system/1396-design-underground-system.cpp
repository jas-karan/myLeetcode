class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>in;
    unordered_map<string,vector<int>>trip;
    
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        in[id] = make_pair(stationName,t);
    }
    
    void checkOut(int id, string stationName, int t) {
        string s = in[id].first+"-"+stationName;
        trip[s].push_back(t-(in[id].second));
        in.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double ans=0.0;
        string s = startStation+"-"+endStation;
        
        for(int t:trip[s]) ans+=t;
        
        return ans/trip[s].size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
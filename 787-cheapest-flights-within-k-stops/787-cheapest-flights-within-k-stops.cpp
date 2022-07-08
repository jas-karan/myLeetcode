class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int sink, int k) {
       
        vector<int> d(n, 1e8);
        d[src] = 0;
        
        for(int i=0; i<=k; i++){
            vector<int> t(d);
            for(auto e:flights)
                t[e[1]] = min(t[e[1]], d[e[0]] + e[2]);
            d = t;
        }
        return d[sink] == 1e8 ? -1 : d[sink];
    }
};
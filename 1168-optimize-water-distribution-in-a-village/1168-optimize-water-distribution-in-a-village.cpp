class UnionFind {
private: vector<int>root;
        
public:
    int cnt;
    UnionFind(int size) {
        cnt=size;
        root = vector<int>(size);
        for (int i = 0; i < size; i++) {
            root[i] = i;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    bool union_(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if( rootX == rootY) return false;
        root[rootY] = rootX;
        cnt--;
        return true;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        UnionFind uf(n+1);
        for(int i=1;i<=n;i++){
            pipes.push_back({0,i,wells[i-1]});
        }
        
        //applying kruskal - choose an edge who connects two trees
        sort(pipes.begin(),pipes.end(),[](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        });
        
        int cost=0;
        for(auto p:pipes){
            if(uf.union_(p[0],p[1])) cost+=p[2];
        }
        return cost;
    }
};
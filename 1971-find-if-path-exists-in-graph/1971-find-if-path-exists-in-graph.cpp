class UnionFind {
    
private: vector<int>root;
        
public:
    
    UnionFind(int size) {
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

    void union_(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        root[rootY] = rootX;
    }

};

class Solution {
public:
//     unordered_set<int>vis;
    
//     bool dfs(vector<vector<int>>&gr,int src,int des){
//         if(src==des) return true;
        
//         vis.insert(src);
        
//         for(int nbr:gr[src]){
//             if(vis.find(nbr)==vis.end()){
//                 if(dfs(gr,nbr,des)) return true;
//             }
//         }
        
//         return false;
//     }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);
        for(auto e:edges) uf.union_(e[0],e[1]);
        
        return uf.find(source)==uf.find(destination);
    }
};
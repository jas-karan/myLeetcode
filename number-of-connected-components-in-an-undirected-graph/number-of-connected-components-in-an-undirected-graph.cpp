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
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        
        for(auto e:edges){
            uf.union_(e[0],e[1]);
        }
        
        return uf.cnt;
    }
};
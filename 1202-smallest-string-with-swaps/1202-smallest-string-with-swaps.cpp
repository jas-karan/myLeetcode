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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind uf(s.length());
        for(auto p:pairs){
            uf.union_(p[0],p[1]);
        }
        
        unordered_map<int,vector<int>>comp;
        
        for(int i=0;i<s.length();i++){
            int root = uf.find(i);
            comp[root].push_back(i);
        }
        
        for(auto c:comp){
            vector<int>indices = c.second;
            vector<int>chars;
            for(int ind:indices){
                chars.push_back(s[ind]);
            }
            sort(begin(chars),end(chars));
            for(int i=0;i<chars.size();i++){
                s[indices[i]]=chars[i];
            }
        }
        
        return s;
    }
};
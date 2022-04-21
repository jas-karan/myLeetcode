class MyHashSet {
public:
    vector<vector<int>>map;
    int PRIME; 
    
    int hash(int key){
        return key%PRIME;    
    }
    
    MyHashSet() {
        PRIME = 10007;
        map = vector<vector<int>>(PRIME);
    }
    
    void add(int key) {
        int h = hash(key);
        if(contains(key)) return;
        map[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        for(auto i=map[h].begin();i!=map[h].end();i++){
            if(*i==key){ 
                map[h].erase(i);
                return;
            }    
        }
    }
    
    bool contains(int key) {
        int h = hash(key);
        for(int k:map[h]){
            if(k==key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
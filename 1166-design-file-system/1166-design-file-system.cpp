class TrieNode{
public:
      unordered_map<string,TrieNode*>child;
      bool isFile;
      int content;
      TrieNode(){
          isFile=false;
          content=0;
      }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
    
    bool insert(vector<string>& path, int value) {
        int n = path.size();
        TrieNode* cur = root;
        for (int i = 0; i < n; ++i) {
            if (cur -> child.find(path[i]) == cur -> child.end()) {
                if (i != n - 1) {
                    return false;
                }
                cur -> child[path[i]] = new TrieNode();
            }
            else {
                if (i == n - 1) {
                    return false; 
                }
            }
            cur = cur -> child[path[i]];
        }
        cur -> isFile = true;
        cur -> content = value;
        return true;
    }

    int find(vector<string>& path) {
        int n = path.size();
        TrieNode* cur = root;
        for (int i = 0; i < n; ++i) {
            if (cur -> child.find(path[i]) == cur -> child.end()) {
                return -1;
            }
            cur = cur -> child[path[i]];
        }
        return cur -> content;
    }
};

class FileSystem {
public:
    Trie*trie;
    FileSystem() {
       trie = new Trie();
    }
    
    vector<string> split(string& path) {
        vector<string> result;
        string cur = "";
        for (int i = 1; i < path.size(); ++i) {
            char c = path[i];
            if (c == '/') {
                result.push_back(cur);
                cur = "";
            }
            else {
                cur.push_back(c);
            }
        }
        result.push_back(cur);
        return result;
    }
    
    bool createPath(string path, int value) {
        vector<string>s = split(path);
        return trie->insert(s,value);
    }
    
    int get(string path) {
        vector<string>s = split(path);
        return trie->find(s);
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
class Solution {
public:
    unordered_map<char, unordered_map<char, char>> isMappingExist;
    
    //check for every substring of length sub.length()
    bool check(string& s, int pos, string& sub) {
        
        // Return if the substring cannot exist
        if (pos + sub.size() > s.size()) {
            return false;
        }
        
        int index = 0;
        
        //either all the chars should be same or there should be a mapping
        for (int i = pos; i < pos + sub.size(); i++) {
            if (sub[index] == s[i] || isMappingExist[sub[index]][s[i]]) {
                index++;
            } else {
                return false;
            }
        }
        
        return true;
    }
    
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        for (vector<char> mapping : mappings) {
            isMappingExist[mapping[0]][mapping[1]] = 1;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (check(s, i, sub)) {
                return true;
            }
        }
        
        return false;
    }
};
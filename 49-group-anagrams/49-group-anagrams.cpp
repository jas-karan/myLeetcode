class Solution {
public:
    string findGroup(string s){
        string g = "";
        int freq[26]={0};
        for(char c:s){
            freq[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]){
                g+=('a'+i);
                g+=to_string(freq[i]);
            }
        }
        return g;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //we have to use somekind of mapping 
        //a representation of each group
        //and that is frequence map of that group
        //eg. abbcc = a1b2c2
        
        unordered_map<string,vector<string>>mp;
        for(string s:strs){
            string g = findGroup(s);
            mp[g].push_back(s);
        }
        
        vector<vector<string>>groups;
        for(auto m:mp) groups.push_back(m.second);
        
        return groups;
        
    }
};
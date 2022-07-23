class Solution {
public:
    unordered_map<string,vector<string>>map;
    
    string group(string&s){
        int freq[26]={0};
        
        string group="";
        for(char c:s){
            freq[c-'a']++;
        }
        
        for(int i=0;i<26;i++){
            group+=(i+'a');
            group+=to_string(freq[i]);
        }
        
        return group;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(string&s:strs){
            map[group(s)].push_back(s);
        }
        
        vector<vector<string>>ans;
        
        for(auto itr:map){
            ans.push_back(itr.second);
        }
        
        return ans;
    }
};
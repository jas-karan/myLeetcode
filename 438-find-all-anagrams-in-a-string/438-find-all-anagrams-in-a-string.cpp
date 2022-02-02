class Solution {
public:
    bool compare(int freq[26],int window[26]){
        for(int i=0;i<26;i++){
            if(freq[i]!=window[i]) return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        if(p.length()>s.length()) return {};
        
        vector<int>indices;
        
        int freq[26]={0};
        for(char ch:p) freq[ch-'a']++;
        
        int window[26]={0};
        for(int i=0;i<p.length();i++) window[s[i]-'a']++;
        if(compare(freq,window)) indices.push_back(0);
        
        for(int i=p.length();i<s.length();i++){
            window[s[i]-'a']++;
            window[s[i-p.length()]-'a']--;
            
            if(compare(freq,window)) indices.push_back(i-p.length()+1);
        }
        
        return indices;
        
    }
};
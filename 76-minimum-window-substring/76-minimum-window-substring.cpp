class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()) return "";
        
        //idea - we maintain a window
        //expand the window unitl it do not have all chars of t
        //shrink it until it has all chars of t
        //and keep updating the length and smallest substring
        
        unordered_map<int,int>mp;
        for(char ch:t) mp[ch]++;
        int reqCount = mp.size();
        
        unordered_map<int,int>window;
        int length=INT_MAX;
        string smallest = "";
        int foundCount = 0;
        
        int l=0,r=0;
        
        while(r<s.length()){
            window[s[r]]++;
            
            //increase the foundCount only iff char is in t && duplicates are also found
            if(mp.find(s[r])!=mp.end() && mp[s[r]]==window[s[r]]){
                foundCount++;
            } 
            r++;
            
            //only iff all the chars of t are found, shrink the window
            while(reqCount==foundCount && l<r){
                if(length>r-l){  //update the current window
                    length=r-l;
                    smallest=s.substr(l,length);
                }
                window[s[l]]--;
                if(mp.find(s[l])!=mp.end() && window[s[l]]<mp[s[l]]){
                    foundCount--;
                }
                l++;
            }
        }
        
        return smallest;
        
    }
};
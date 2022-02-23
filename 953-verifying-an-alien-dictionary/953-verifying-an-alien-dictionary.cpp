class Solution {
public:
    unordered_map<char,int>mp; //to store order
    bool isLess(string a, string b){
        int l = min(a.length(),b.length());
        for(int i=0;i<l;i++){
            if(a[i]!=b[i]){
                return mp[a[i]]<mp[b[i]];
            }
        }
        return a.length()<=b.length();
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        //just check adjacent words
       
        for(int i=0;i<order.length();i++) mp[order[i]]=i;
        
        for(int i=1;i<words.size();i++){
            if(!isLess(words[i-1],words[i])) return false;
        }
        
        return true;
    }
};
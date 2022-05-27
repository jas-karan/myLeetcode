class Solution {
public:
    unordered_set<string>map;
    
    bool canBreak(string w,int ind){
        if(ind==w.length()) return true;
    
        string curr = "";
        for(int i=ind;i<w.length();i++){
            curr+=w[i];
            if(map.find(curr)!=map.end()){
                if(ind==0 && i==w.length()-1) return false;
                if(canBreak(w,i+1)) return true;
            }
        }
        
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(string w:words){
            map.insert(w);
        }
        
        vector<string>res;
        for(string w:words){
            if(w.length()>0 && canBreak(w,0)){
                res.push_back(w);
            }
        }
        
        return res;
    }
};
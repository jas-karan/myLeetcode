class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26,0);
        for(auto c:s) freq[c-'a']++;
        
        sort(freq.begin(),freq.end(),greater<int>());
        
        int nextfreq = freq[0];
        int del=0;
        
        for(int f:freq){
            nextfreq= min(f,nextfreq);
            
            del += f-nextfreq;
            
            if(nextfreq>0) nextfreq--;
        }
        
        return del;
    }
};
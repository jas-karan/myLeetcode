class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        int freq[26]={0};
        for(char c:s) freq[c-'a']++;
        
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++) if(freq[i]) pq.push({freq[i],(char)(i+'a')});
        
        string res = "";
        
        while(pq.size()>1){
            auto [ac,a] = pq.top(); pq.pop();
            auto [bc,b] = pq.top(); pq.pop();
            
            res+=a; res+=b;
            ac--;  bc--;
            
            if(ac) pq.push({ac,a});
            if(bc) pq.push({bc,b});
        }
        
        if(pq.size()){
            if(pq.top().first>1) return "";
            else res+=pq.top().second;
        } 
        
        return res;
    }
};
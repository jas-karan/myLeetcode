class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>set;
        for(string&s:words) set[s]++;
        
        vector<int>ans;
        int len = words[0].length();
        int n = s.length();
        int w = words.size();
        
        for(int i=0;i<=n-(len*w);i++){
            
            unordered_map<string,int>cur;
            
            for(int j=i;j<=i+(w-1)*len;j+=len){
                string c = s.substr(j,len);
                cur[c]++;
            }
            
            bool f=true;
            for(auto e:set){
                if(set[e.first]!=cur[e.first]){
                    f=false;
                    break;
                }
            }
            
            if(f) ans.push_back(i);
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int>mp;
        
        for(string s:cpdomains){
            int i=0;
            while(s[i]!=' ') i++;
            int num = stoi(s.substr(0,i));
            
            string subd = "";
            for(int j=s.length()-1;j>i;j--){
                if(s[j]=='.'){
                    mp[subd]+=num;
                }
                subd = s[j]+subd;
            }
            mp[subd]+=num;
        }
        
        vector<string>ans;
        for(auto m:mp){
            ans.push_back(to_string(m.second)+" "+m.first);
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size(),q = queries.size();
        for(string&s:queries) sort(s.begin(),s.end());
        for(string&s:words) sort(s.begin(),s.end());
        
        vector<int>ans;
        
        for(string q:queries){
            int f1=0;
            for(char c:q){
                if(c==q[0]) f1++;
                else break;
            }
            int res = 0;
            for(string w:words){
                int f2 = 0;
                for(char c:w){
                    if(c==w[0]) f2++;
                    else break;
                }
                
                if(f1<f2)res++;
            }
            
            ans.push_back(res);
        }
        
        return ans;
    }
};
class Solution {
public:
    long long appealSum(string s) {
        int n = s.length();
        vector<long long>L(n,-1);
        vector<int>lpos(26,-1);
        
        for(int i=0;i<n;i++){
            L[i]=i-lpos[s[i]-'a'];
            lpos[s[i]-'a']=i;
        }
        
        
        long long ans=0;
        
        for(int i=0;i<n;i++){
            ans += (L[i]*(n-i));
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long val) {
        int n = s.size(), m = p.size();
        
        sort(p.begin(),p.end());
        
        vector<int> ans;
        for(auto &x : s)
        {
            auto req = val / x;
            if(val%x==0)
                req--;
            
            int ind = upper_bound(p.begin(),p.end(),req) - p.begin();
            ans.push_back(m-ind);
        }
        return ans;
    }
};
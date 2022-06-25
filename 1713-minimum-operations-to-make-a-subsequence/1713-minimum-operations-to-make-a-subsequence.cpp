class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        //longest common subsequence = TLE
        //LCS to LIS (by indices)
        //[6,4,8,1,3,2] -> [0,1,2,3,4,5]
        //[4,7,6,2,3,8,6,1] -> [1,-1,0,5,4,2,0,3]   here lis=0,2,3
        
        unordered_map<int, int> m;
        
        int n = target.size();
        
        for (int i = 0; i < n; ++i) m[target[i]] = i;
        
        vector<int> indexes;
        for (auto x: arr) {
            if (m.find(x) != m.end()) indexes.push_back(m[x]);
        }
        
        vector<int> lis;
        for (auto x : indexes) {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if (it == lis.end()) lis.push_back(x); 
            else *it = x; 
        }
        return n - lis.size();
    }
};
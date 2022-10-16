class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        int n1 = nums1.size(), n2 = nums2.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({nums1[0]+nums2[0],{0,0}});
        
        while(pq.size() && ans.size()<k){
            auto [val,p] = pq.top();
            int i = p.first, j = p.second;
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});
            
            if(j<n2-1) pq.push({nums1[i]+nums2[j+1],{i,j+1}});
            if(j==0 && i<n1-1) pq.push({nums2[j]+nums1[i+1],{i+1,j}});
        }
        
        return ans;
    }
};
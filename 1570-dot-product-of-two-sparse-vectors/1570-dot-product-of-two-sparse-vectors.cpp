class SparseVector {
public:
    unordered_map<int,int>mp;
    int sz;
    
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]) mp[i]=nums[i];
        }
        sz=nums.size();
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for(int i=0;i<sz;i++){
            if(vec.mp.find(i)!=vec.mp.end() && mp.find(i)!=mp.end()){
                res+= (vec.mp[i]*mp[i]);
            }
        }
        
        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
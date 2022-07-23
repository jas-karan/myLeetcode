//see range sum query immutable and mutable for BIT(binary indexed tree)
class Solution {
public:
    int size = 2*1e4+2;
    int offset = 1e4;
    vector<int>BIT;
    vector<int>res;
    
    vector<int> countSmaller(vector<int>& nums) {
        //bucket for each value
        //iterate from right, count bucket size for all buckets
        //update bucket value for current number
        BIT=vector<int>(size,0);
        
        for(int i=nums.size()-1;i>=0;i--){
            int smaller = queryBIT(nums[i]+offset);
            res.push_back(smaller);
            updateBIT(nums[i]+offset,1);
        }
        
        reverse(begin(res),end(res));
        
        return res;
    }
    
    void updateBIT(int ind,int val){
        ind++; //1-indexing
        while(ind<size){
            BIT[ind]+=val;
            ind+=(ind&-ind);
        }   
    }
    
    int queryBIT(int ind){
        int res=0;
        while(ind>0){
            res+=BIT[ind];
            ind-=(ind&-ind);
        }
        return res;
    }
};
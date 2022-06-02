class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>res;
        int sz = nums.size();
        int p=sz,n=-1;
        
        for(int i=0;i<sz;i++){
            if(nums[i]<0) n=i;
            if(nums[sz-i-1]>=0) p=sz-i-1;
        }
        
        
        while(n>=0 && p<sz){
            if(abs(nums[p])<=abs(nums[n])){
                res.push_back(nums[p]*nums[p]);
                p++;
            }
            else{
                res.push_back(nums[n]*nums[n]);
                n--;
            }
        }
        
        while(n>=0){
            res.push_back(nums[n]*nums[n]);
            n--;
        }
        while(p<sz){
            res.push_back(nums[p]*nums[p]);
            p++;
        }
        
        return res;
    }
};
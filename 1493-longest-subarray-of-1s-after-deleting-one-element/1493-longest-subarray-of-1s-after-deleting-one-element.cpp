class Solution {
public:
    int longestSubarray(vector<int>& num) {
        int res = 0;
        int l=0;
        int del=0;
        int r=0;
        
        while(r<num.size()){
            if(num[r]==0) del++;
            while(del>1){
                if(num[l]==0) del--;
                l++;
            }
            res = max(res,r-l+1-del);
            r++;
        }
        
        if(res==num.size()) return res-1;
        return res;
    }
};
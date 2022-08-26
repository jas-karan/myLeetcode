class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg=0;
        bool zero=false;
        
        for(int n:nums){
            if(n==0) zero=true;
            if(n<0) neg++;
        }
        
        if(zero) return 0;
        if(neg%2==1) return -1;
        return 1;
    }
};
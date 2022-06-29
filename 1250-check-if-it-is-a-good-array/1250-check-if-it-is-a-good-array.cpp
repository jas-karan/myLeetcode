class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        //if for any a,b,c,.. gcd(a,b,c,..)=d 
        //then there exist x,y,z,.. st, a*x+b*y+c*z+...=d
        
        int gcd=nums[0];
        for(int i=1;i<nums.size();i++) gcd=__gcd(gcd,nums[i]);
        return gcd==1;
    }
};
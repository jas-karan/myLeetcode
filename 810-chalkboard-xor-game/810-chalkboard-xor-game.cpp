class Solution {
public:
    bool xorGame(vector<int>& nums) {
        //xor =0 alice wins already
        //xor!=0 and size is even alice will win
        
        //xor!=0 -> odd no. of elements with some set bit 
        //means that atleast one element (coz size is even) with that set bit = 0 
        //alice will remove that number, after that xor will not be zero
        //bcoz those odd elements are still there/
        
        int xor_=0;
        for(int n:nums) xor_^=n;
        return (xor_==0) || nums.size()%2==0;
    }
};
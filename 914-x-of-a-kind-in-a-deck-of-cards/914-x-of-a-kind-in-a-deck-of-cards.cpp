class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>count;
        
        for(int n:deck) count[n]++;
        
        //take minimum of counts and if all counts are divisible by min
        //then we can divide into groups each of size min
        //this approach is not correct if we have counts 4 and 6
        //then min is 4 and 6 is not divisible by 4
        //but we are able to divide into groups of 2.
        //what is 2? it is greatest common divisor
        
        //if greatest common divisor is >1 then true else false
        
        int gcd=-1;
        
        for(auto c:count){
            if(gcd==-1) gcd=c.second;
            else gcd = __gcd(gcd,c.second);
        }
        
        return gcd>1;
    }
};
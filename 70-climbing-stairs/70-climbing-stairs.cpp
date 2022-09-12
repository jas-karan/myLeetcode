class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        
        int last = 2, lastSecond = 1;
        for(int i=3;i<=n;i++){
            int t = last;
            last = lastSecond+last;
            lastSecond = t;
        }
        
        return last;
    }
};
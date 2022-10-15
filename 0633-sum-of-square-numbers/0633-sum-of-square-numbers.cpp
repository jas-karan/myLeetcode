class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0,b = sqrt(c);
        while(a<=b){
            long long t = a*a+b*b;
            if(t == c) return true;
            if(t > c) b--;
            else a++;
        }
        return false;
    }
};
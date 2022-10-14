class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        if(x==1) return 1;
        if(n==0) return 1;
        if(n<0){
            x = 1/x;
            n=abs(n);
        }
        
        if(n%2==0){
            double t = myPow(x,n/2);
            return t*t;
        }
        else{
            double t = myPow(x,n-1);
            return t*x;
        }
        
        return 1;
    }
};
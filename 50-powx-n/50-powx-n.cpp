class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            x = 1/x;
            n = abs(n);
        }
        if(n==0) return 1;
        if(n==1) return x;
        
        double sol = 0.0;
        if(n%2==0){
            sol = myPow(x,n/2);
            sol = sol*sol;
        }
        else{
            sol = x*myPow(x,n-1);
        }
        
        return sol;
    }
};
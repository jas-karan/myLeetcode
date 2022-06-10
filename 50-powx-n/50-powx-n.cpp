class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        if(x==1) return 1;
        if(n==0) return 1;
        
        int n1 = n/2;
        if(n<0){
            x = 1/x;
            n1*=-1;
        }
        
        double sol = myPow(x,n1);
        sol = sol*sol;
        if(n%2!=0) sol*=x;
        
        return sol;
    }
};
class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n<3) return 1;
        
        int a=0,b=1,c=1;
        for(int i=3;i<=n;i++){
            int t1=a,t2=b;
            a=b;
            b=c;
            c=c+t1+t2;
        }
        
        return c;
    }
};
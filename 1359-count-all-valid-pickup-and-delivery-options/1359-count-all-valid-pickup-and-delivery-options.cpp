class Solution {
public:
    int countOrders(int n) {
        if(n==1) return 1;
        if(n==2) return 6;
        
        int prev = 6;
        long long curr;
        
        for(long long i=3;i<=n;i++){
            long long spaces = 2*i-1;
            long long for_each_space = (spaces*(spaces+1))/2;
            long long total = for_each_space*prev;
            prev = (int)(total%1000000007);
        }
        
        return prev;
    }
};
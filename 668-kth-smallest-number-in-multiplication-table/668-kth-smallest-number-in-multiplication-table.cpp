class Solution {
public:
    int lessthan(int mi,int m,int n,int k){
        int cnt=0;
        for(int i=1;i<=m;i++){
            cnt+= min(mi/i,n);   
        }
        return cnt;
    }
    
    int findKthNumber(int m, int n, int k) {
        //binary search
        
        int l=1,h=m*n;
        
        int ans;
        
        while(l<=h){
            int mi = l+(h-l)/2;
            
            if(lessthan(mi,m,n,k)>=k){
                ans = mi;
                h=mi-1;
            }
            else l=mi+1;
        }
        
        return ans;
    }
};
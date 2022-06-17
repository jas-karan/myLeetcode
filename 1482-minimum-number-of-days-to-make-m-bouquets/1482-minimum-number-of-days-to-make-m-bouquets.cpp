class Solution {
public:
    bool pos(vector<int>b,int m,int k,int d){
        int cnt=0;
        int cur=0;
        for(int i:b){
            if(i<=d) cur++;
            else cur=0;
            
            if(cur>=k){
                cnt++;
                cur=0;
            }
        }
        
        return cnt>=m;
    }
    
    int minDays(vector<int>& bloom, int m, int k) {
        int l=INT_MAX,r=INT_MIN;
        for(int b:bloom){l=min(l,b); r=max(r,b);}
        
        int ans = -1;
        
        while(l<=r){
            int d = l+(r-l)/2;
            
            if(pos(bloom,m,k,d)){
                ans = d;
                r=d-1;
            }
            else l=d+1;
        }
        
        return ans;
    }
};
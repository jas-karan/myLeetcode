class Solution {
public:
    int helper(int present,int copied,int n){
        if(present>n) return INT_MAX;  //wrong operations
        if(present==n) return 0;  //exactly n are required
        
        int copy_paste = helper(present+present,present,n);
        if(copy_paste!=INT_MAX) copy_paste+=2;
        int paste = helper(present+copied,copied,n);
        if(paste!=INT_MAX) paste+=1;
        
        return min(copy_paste,paste);
    }
    
    int minSteps(int n) {
        if(n<2) return 0;
        return 1+helper(1,1,n);
    }
};
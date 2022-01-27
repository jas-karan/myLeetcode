class Solution {
public:
    bool possible(vector<int>piles, int k,int h){
        int hrs = 0;
        
        for(int p:piles){
            hrs+=(ceil((p*1.0)/k));
        }
        return (hrs<=h);
    }
    
    int minEatingSpeed(vector<int>& piles, int hr) {
        //we look for speed (bananas per hr)
        //highest will be one max pile. (at max only one pile can be eaten in an hr)
        
        int l=1,h=INT_MIN;
        
        for(int p:piles) h=max(h,p);
        
        int speed;
        
        //we use equality since value is present in search space
        while(l<=h){
            int m = l+(h-l)/2;
            
            if(possible(piles,m,hr)){
                speed = m;   //keep updating last found 
                h = m-1;
            }
            else l = m+1;
        }
        
        return speed;
    }
};
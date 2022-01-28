class Solution {
public:
    bool possible(vector<int>weights, int max_days, int cap){
        int days = 1;
        int curr_weight = 0;
        
        for(int w:weights){
            curr_weight += w;
            if(curr_weight > cap){
                days++;
                curr_weight = w;
            }
        }
        
        return days<=max_days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        //minimum capacity of ship must be to ship the heaviest package
        //maximum capacity should be to ship all together
        
        int l=INT_MIN,h=0;
        for(int w:weights){
            l = max(l,w);
            h += w;
        }
        
        int min_capacity;
        
        while(l<=h){
            int mid = l + (h-l)/2;
            
            //if it is possible to ship (with this ship capacity) within d days
            if(possible(weights,days,mid)){
                min_capacity = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }
        
        return min_capacity;
    }
};
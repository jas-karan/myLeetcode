class Solution {
public:
//     pair<int,int> floor_ceil(vector<int>h,int rad){
//         int l=0,r=h.size()-1;
//         int f = INT_MIN;
//         int c = INT_MAX;
//         while(l<=r){
//             int m=l+(r-l)/2;
//             if(h[m]==rad) return {h[m],h[m]};
//             else if(h[m]<rad){
//                 f=h[m];
//                 l=m+1;
//             }
//             else{
//                 c=h[m];
//                 r=m-1;
//             }
//         }
        
//         return {f,c};
//     }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
//         sort(heaters.begin(), heaters.end());
//         //for each house,
//         //we will find closest heaters to it on left and right ie; ceil and floor
//         //and nearest heater from left and right (bcoz we want minimum radius)
        
//         int radius = INT_MIN;
//         for(int i=0;i<houses.size();i++){
//             pair<int,int>p = floor_ceil(heaters,houses[i]);
//             int f = p.first;
//             int c = p.second;
//             int curr;
//             if(c==INT_MAX) curr=houses[i]-f;
//             else if(f==INT_MIN) curr=c-houses[i];
//             else curr = min(houses[i]-f,c-houses[i]);
//             radius = max(radius,curr);
//         }
    
//         return radius;
        
// -------------- time limit exceeded --------------  
// we can use two pointer approach for storing nearest heater radius
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int h = houses.size(),n=heaters.size();
        vector<int>radii(h,INT_MAX);
        int i=0,j=0;
        
        //first we find right side nearest heater
        while(i<h && j<n){
            if(houses[i]<=heaters[j]){
                radii[i]=(heaters[j]-houses[i]);
                i++;  //check next house for current heater
            }
            else j++; //go to next heater
        }
        
        //now on left side and update radii
        i=h-1,j=n-1;
        while(i>=0 && j>=0){
            if(houses[i]>=heaters[j]){
                radii[i]=min(radii[i],(houses[i]-heaters[j]));
                i--;  //check next house for current heater
            }
            else j--; //go to next heater
        }
        
        int radius = INT_MIN;
        for(int r:radii) radius=max(radius,r);
        return radius;
    }
};
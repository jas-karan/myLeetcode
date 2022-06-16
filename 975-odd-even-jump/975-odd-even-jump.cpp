class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        
        //alternate jumps ->first to higher element then to a lower element
        //we start from last and keep storing the elements in map 
        //if higher exists at i then we then we take lower(i) (for second jump)
        //and vice versa
        
        vector<int>higher(n),lower(n);
        map<int,int>map;
        
        higher[n-1]=1;
        lower[n-1]=1;
        map[arr[n-1]]=n-1;
        int res =1;
        
        for(int i=n-2;i>=0;i--){
            auto h = map.lower_bound(arr[i]);  //lowerbound ->notlessthan
            auto l = map.upper_bound(arr[i]);  //greater element so, -1 for smaller
            
            if(h!=map.end()) higher[i] = lower[h->second];
            if(l!=map.begin()) lower[i] = higher[(--l)->second];
            
            if(higher[i]) res++;  //if we can start from here (means first (odd) jump)
            map[arr[i]]=i;
        }
        
        return res;
        
    }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         priority_queue<pair<int,int>>pq;
        
//         for(int i=0;i<arr.size();i++){
//             if(pq.size()<k) pq.push({abs(arr[i]-x),arr[i]});
//             else{
//                 if(pq.top().first > abs(arr[i]-x)){
//                     pq.pop();
//                     pq.push({abs(arr[i]-x),arr[i]});
//                 }
//             }
//         }
        
//         vector<int>res;
//         while(!pq.empty()){
//             res.push_back(pq.top().second);
//             pq.pop();
//         }
//         // values will not be in sorted order necessarily
//         sort(res.begin(), res.end());
        
//         return res;
        
        int n = arr.size();
        int lo=0,hi=n-1;
        int ind=-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(arr[mid]==x){ind=mid; break;}
            else if(arr[mid]<x) lo=mid+1;
            else hi=mid-1;
        }
        //if x was not found then hi+1 will be insert position of x
        ind = ind==-1 ? hi+1:ind;
        cout<<ind<<endl;
        lo = ind-1;
        hi = ind;
        while(lo>=0 && hi<n &&k>0){
            if(abs(arr[lo]-x)<=abs(arr[hi]-x)) lo--;
            else hi++;
            if(--k==0) break;
        }
        
        while(lo>=0 && k>0){lo--; k--;}
        while(hi<n && k>0){hi++; k--;}
        
        vector<int>res;
        for(int i=lo+1;i<hi;i++) res.push_back(arr[i]);
        
        return res;
    }
};
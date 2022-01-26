class Solution {
public:
    int search(vector<int>& arr, int x) {
        int n = arr.size();
        
        int l=0,h=n-1;
        while(l<=h){
            int m =(l+h)/2;
            
            if(arr[m]==x) return m;
            else{
                if(arr[0]<=arr[m]){
                    if(arr[0]<=x&&x<arr[m]) h=m-1;
                    else l=m+1;
                }
                else{
                    if(arr[m]<x&&x<=arr[h]) l=m+1;
                    else h=m-1;
                }
            }
        }
        
        return -1;
    }
};
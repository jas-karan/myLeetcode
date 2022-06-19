class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res=0;
        int sum = 0;
        for(int i=0;i<k-1;i++) sum+=arr[i];
        
        for(int i=k-1;i<arr.size();i++){
            sum+=arr[i];
            if(i>=k) sum-=arr[i-k];
            if(sum/k>=threshold) res++;
        }
        
        return res;
    }
};
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        //compare with sorted array
        //chunk sorted is just a permutation of originial array
        //so when all the elements of chunk are found ans++
        
        int ans=0;
        long long sum1=0,sum2=0;
        
        vector<int>sorted=arr;
        sort(sorted.begin(),sorted.end());
        
        for(int i=0;i<arr.size();i++){
            sum1+=arr[i];
            sum2+=sorted[i];
            
            if(sum1==sum2){
                ans++;
                sum1=sum2=0;
            }
        }
        
        return ans;
    }
};
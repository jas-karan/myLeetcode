class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
//         vector<int>res;
//         int sz = nums.size();
//         int p=sz,n=-1;
        
//         for(int i=0;i<sz;i++){
//             if(nums[i]<0) n=i;
//         }
//         p=n+1;
        
//         while(n>=0 && p<sz){
//             if(abs(nums[p])<=abs(nums[n])){
//                 res.push_back(nums[p]*nums[p]);
//                 p++;
//             }
//             else{
//                 res.push_back(nums[n]*nums[n]);
//                 n--;
//             }
//         }
        
//         while(n>=0){
//             res.push_back(nums[n]*nums[n]);
//             n--;
//         }
//         while(p<sz){
//             res.push_back(nums[p]*nums[p]);
//             p++;
//         }
        
//         return res;
        
        int i = 0, j = a.size() - 1, k = j;
        vector <int> ret(k + 1, 0);
        while (k >= 0) {
            if (abs(a[i]) > abs(a[j])) ret[k--] = a[i] * a[i++];
            else ret[k--] = a[j] * a[j--];
        }
        return ret;
    }
};
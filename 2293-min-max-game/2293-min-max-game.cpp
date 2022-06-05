class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        // while(nums.size()>1){
        //     vector<int>curr;
        //     bool f=false;
        //     for(int i=0;i<nums.size();i+=2){
        //         if(f){
        //             curr.push_back(max(nums[i],nums[i+1]));
        //         }
        //         else curr.push_back(min(nums[i],nums[i+1]));
        //         f=!f;
        //     }
        //     nums=curr;
        // }
        // return nums.back();
        
        int n = nums.size();
        int p = log2(n);
        queue<int> q;
        for (int i=0;i<n;i++)
            q.push(nums[i]);
        while (p--) {
        
            int sz = q.size()/2;
            int i = 0;
            while (sz--) {
                int a = q.front();
                q.pop();
                int b = q.front();
                q.pop();
                if (i%2 == 0)
                    q.push(min(a,b));
                else 
                    q.push(max(a, b));
                i++;
            }
        }
        
        return q.front();
    }
};
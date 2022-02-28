class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return {};
        
        vector<string>res;
        int first = nums[0];
        int last = nums[0];
        
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                last = nums[i];
            }
            else{
                if(first==last){
                    res.push_back(to_string(first));
                }
                else{
                    string cur = to_string(first)+"->"+to_string(last);
                    res.push_back(cur);
                }
                first = last = nums[i];
            }
        }
        if(first==last){
            res.push_back(to_string(first));
        }
        else{
            string cur = to_string(first)+"->"+to_string(last);
            res.push_back(cur);
        }
        return res;
    }
};
class Solution {
public:
    void dfs(vector<int>&nums,int ind,int t,vector<int>&cur, vector<vector<int>>&ans){
        if(nums.size()<=ind){
            if(cur.size() && t==0) ans.push_back(cur);
            return;
        }
        
        if(t<0) return;
        
        cur.push_back(nums[ind]);
        dfs(nums,ind,t-nums[ind],cur,ans);
        cur.pop_back();
        
        dfs(nums,ind+1,t,cur,ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>cur;
        vector<vector<int>>ans;
        
        sort(candidates.begin(),end(candidates));
        dfs(candidates,0,target,cur,ans);
        
        return ans;
    }
};
class Solution {
public:
    void helper(vector<int>arr,int x,vector<int>&curr, vector<vector<int>>&res,int i){
        if(i<0){
            if(x==0) res.push_back(curr);
            return;
        }
        if(x<0) return;
        curr.push_back(arr[i]);
        helper(arr,x-arr[i],curr,res,i);
        curr.pop_back();
        helper(arr,x,curr,res,i-1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int x) {
        vector<vector<int>>res;
        vector<int>curr;
        
        helper(arr,x,curr,res,arr.size()-1);
        
        return res;
    }
};
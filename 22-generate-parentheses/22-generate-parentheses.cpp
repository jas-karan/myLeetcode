class Solution {
public:
    void helper(string curr, vector<string>&ans,int n,int k){
        if(k==0 && n==0){
            ans.push_back(curr);
            return;
        }
        
        if(n>0){
            helper(curr+'(',ans,n-1,k+1);
        }
        if(k>0){
            helper(curr+')',ans,n,k-1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        helper("",ans,n,0);
        return ans;
    }
};
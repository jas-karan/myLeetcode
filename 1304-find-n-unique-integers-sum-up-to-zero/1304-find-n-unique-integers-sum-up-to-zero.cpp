class Solution {
public:
    vector<int> sumZero(int n) {
        int var=1;
        vector<int>ans;
        while(n>1){
            ans.push_back(var);
            ans.push_back(-var);
            n-=2;
            var++;
        }
        
        if(n) ans.push_back(0);
        
        return ans;
    }
};
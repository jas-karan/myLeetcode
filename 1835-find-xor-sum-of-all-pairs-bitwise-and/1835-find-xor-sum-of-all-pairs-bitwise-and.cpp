class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        //a=[1,2] b=[6,5]
        //ans = (1&6)^(1&5)^(2&6)^(2&5)
        //ans =  1&(6^5) ^ 2&(6^5)
        //ans = (6^5) & (1^2)   :)
        
        int a=0,b=0;
        for(int i:arr1) a^=i;
        for(int i:arr2) b^=i;
        
        return a&b;    
    }
};
class Solution {
public:
    int getNext(int n){
        int ans = 0;
        while(n){
            int d = n%10;
            ans = ans+(d*d);
            n/=10;
        }
        
        return ans;
    }
    
    bool isHappy(int n) {
        unordered_set<int>set;
        
        while(n!=1 && set.count(n)==0){
            set.insert(n);
            n = getNext(n);
        }
        
        return n==1;
    }
};
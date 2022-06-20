class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<int>cnt({'a','e','i','o','u'});
        
        int res = 0;
        int curr=0;
        for(int i=0;i<k-1;i++){
            if(cnt.count(s[i])) curr++;
        }
        
        
        for(int i=k-1;i<s.length();i++){
            if(cnt.count(s[i])) curr++;
            if(i>=k && cnt.count(s[i-k])) curr--;
            res=max(res,curr);
        }
        
        
        
        return res;
    }
};
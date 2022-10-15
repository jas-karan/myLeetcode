class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        int l = 0, r = n-1;
        unordered_set<char>v({'a','i','e','o','u','A','I','E','O','U'});
        
        while(l<r && v.find(s[l])==v.end()) l++;
        while(l<r && v.find(s[r])==v.end()) r--;
        
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
            while(l<r && v.find(s[l])==v.end()) l++;
            while(l<r && v.find(s[r])==v.end()) r--;
        }
        return s;
    }
};
class Solution {
public:
    
    int longestSubsequence(string s, int k) {
        int zeroes = 0, ones = 0;
        for(auto &i : s) {
            if(i == '0') zeroes++;
        }
        
        long long x = 0;
        reverse(s.begin(), s.end());
        
        for(int i = 0; i < s.size() ; i++) {
            if(x+pow(2, i) > k) break;
            if(s[i] == '0') continue;
            ones++;
            x += pow(2, i);
        }
        return zeroes + ones;
    }
};
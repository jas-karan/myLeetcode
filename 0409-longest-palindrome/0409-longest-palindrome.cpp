class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<int,int>f;
        for(char c:s) f[c]++;
        bool flag=false;
        int len = 0;
        for(auto f_:f){
            int t = f_.second;
            int cnt = t/2;
            len+=(2*cnt);
            if(t%2) flag=true;
        }
        return len+flag;
    }
};
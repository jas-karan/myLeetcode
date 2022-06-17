class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int>left,right;
        
        for(int i=0;i<s.length();i++) right[s[i]-'a']++;
        
        int res = 0;
        for(int i=0;i<s.length()-1;i++){
            left[s[i]-'a']++;
            right[s[i]-'a']--;
            if(right[s[i]-'a']==0) right.erase(s[i]-'a');
            if(left.size()==right.size()) res++;
        }
        
        return res;
   
    }
};
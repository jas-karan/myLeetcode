class Solution {
public:
    void rev(vector<char>&s,int i,int j){
        while(i<j) swap(s[i++],s[j--]);    
    }
    
    void reverseWords(vector<char>& s) {
        for(int i=0;i<s.size();i++){
            int start=i;
            while(i<s.size() && s[i]!=' ') i++;
            rev(s,start,i-1);
        }
        reverse(begin(s),end(s));
    }
};
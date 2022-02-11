class Solution {
public:
    bool areSame(string a,string b,int l,int r){
        int freq[26]={0};
        for(int i=0;i<a.length();i++){
            freq[a[i]-'a']++;
        }
        for(int i=l;i<=r;i++){
            freq[b[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()) return false;
        
        int n = s1.length();
        int l = 0;
        for(int r=n-1;r<s2.length();r++){
            if(areSame(s1,s2,l,r)) return true;
            l++;
        }
        
        return false;
    }
};
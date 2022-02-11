class Solution {
public:
    bool areSame(int a[],int b[]){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()) return false;
        
        int n = s1.length();
        int a[26]={0};
        int b[26]={0};
        
        for(int i=0;i<n;i++) a[s1[i]-'a']++;
        for(int i=0;i<n;i++) b[s2[i]-'a']++;
        if(areSame(a,b)) return true;
        
        for(int i=n;i<s2.length();i++){
            b[s2[i]-'a']++;
            b[s2[i-n]-'a']--;
            if(areSame(a,b)) return true;
        }
        
        return false;
    }
};
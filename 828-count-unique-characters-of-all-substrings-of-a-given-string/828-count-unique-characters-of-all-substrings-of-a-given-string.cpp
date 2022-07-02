class Solution {
public:
    int uniqueLetterString(string s) {
        //every char should occur only once in substring
        //for char s[i], contribution is L[i]*R[i]
        //L[i]->#chars between left last occurence and i
        //R[i]->#chars between i and right first occurence 
        
        int n=s.length();
        vector<long>L(n,-1),R(n,-1);
        vector<long>lpos(26,-1),rpos(26,n);
        
        for(int i=0;i<n;i++){
            L[i]=i-lpos[s[i]-'A'];
            lpos[s[i]-'A']=i;
        }
        for(int i=n-1;i>=0;i--){
            R[i]=rpos[s[i]-'A']-i;
            rpos[s[i]-'A']=i;
        }
        
        long ans=0;
        for(int i=0;i<n;i++){
            ans = (ans+(L[i]*R[i]))%1000000007;
        }
        
        return ans;
    }
};
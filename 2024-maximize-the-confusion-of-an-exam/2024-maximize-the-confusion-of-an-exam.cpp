class Solution {
public:
    int maxConsecutiveAnswers(string key, int k) {
        int ans = 0;
        int ch = 0;
        int l=0,r=0;
        while(r<key.length()){
            if(key[r]=='F') ch++;
            while(ch>k){
                if(key[l]=='F') ch--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        
        ch=0,l=0,r=0;
        while(r<key.length()){
            if(key[r]=='T') ch++;
            while(ch>k){
                if(key[l]=='T') ch--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        
        return ans;
    }
};
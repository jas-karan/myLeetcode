class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<int,int>cnt;
        cnt['a']=0,cnt['e']=0,cnt['i']=0,cnt['o']=0,cnt['u']=0;
        
        for(int i=0;i<k-1;i++){
            if(cnt.count(s[i])) cnt[s[i]]++;
        }
        
        int res = 0;
        for(int i=k-1;i<s.length();i++){
            if(cnt.count(s[i])) cnt[s[i]]++;
            if(i>=k && cnt.count(s[i-k])) cnt[s[i-k]]--;
            int curr=0;
            for(auto c:cnt) curr+=c.second;
            res=max(res,curr);
        }
        
        
        
        return res;
    }
};
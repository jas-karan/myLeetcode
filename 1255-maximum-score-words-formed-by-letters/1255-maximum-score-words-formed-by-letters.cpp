class Solution {
public:
    int call(int i,vector<string>words,vector<int>mp,vector<int>score){
        if(i==words.size()) return 0;
        
        int a = call(i+1,words,mp,score);
        
        int curr = 0;
        
        bool flag=true;
        for(char c:words[i]){
            if(mp[c-'a']==0){
                flag=false;
                curr=0;
                break;
            }
            curr+=score[c-'a'];
            mp[c-'a']--;
        }
        
        if(!flag) return a;
        
        int b = call(i+1,words,mp,score);
        
        return max(a,curr+b);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>mp(26,0);
        
        for(auto l:letters) mp[l-'a']++;
        
        return call(0,words,mp,score);
    }
};
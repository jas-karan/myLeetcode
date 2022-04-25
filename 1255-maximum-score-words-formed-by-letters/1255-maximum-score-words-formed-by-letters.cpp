class Solution {
public:
    int call(int i,vector<string>words,unordered_map<char,int>mp, vector<int>score){
        if(i==words.size()) return 0;
        
        int a = call(i+1,words,mp,score);
        int curr = 0;
        unordered_map<char,int>temp=mp;
        
        bool flag=true;
        for(char c:words[i]){
            if(mp.find(c)==mp.end() || mp[c]==0){
                flag=false;
                curr=0;
                break;
            }
            curr+=score[c-'a'];
            mp[c]--;
        }
        
        if(!flag) return a;
        
        int b = call(i+1,words,mp,score);
        
        mp = temp;
        
        return max(a,curr+b);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int>mp;
        for(auto l:letters) mp[l]++;
        
        return call(0,words,mp,score);
    }
};
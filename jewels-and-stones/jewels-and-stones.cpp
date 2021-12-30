class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char>mp;
        for(char ch:jewels) mp.insert(ch);
        
        int res=0;
        for(char ch:stones) if(mp.find(ch)!=mp.end()) res++;
        
        return res;
    }
};
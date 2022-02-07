class Solution {
public:
    char findTheDifference(string s, string t) {
        // unordered_map<char,int>set;
        // for(auto c:s) set[c]++;
        // for(auto c:t){
        //     if(set.count(c)==0)
        //         return c;
        //     set[c]--;
        //     if(set[c]==0) set.erase(c);
        // }
        // return ' ';
        
        // O(1) Space -
        char r=0;
        for(char c:s) r ^=c;
        for(char c:t) r ^=c;
        return r;
    }
};
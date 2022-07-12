class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int i=-1,j=-1;
        int n=wordsDict.size();
        int dis=n;
        
        for(int k=0;k<n;k++){
            if(wordsDict[k]==word1) i=k;
            if(wordsDict[k]==word2) j=k;
            
            if(i!=-1&&j!=-1) dis=min(dis,abs(i-j));
        }
        
        return dis;
    }
};
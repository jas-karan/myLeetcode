class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string,vector<int>>map;
        for(int i=0;i<wordsDict.size();i++) map[wordsDict[i]].push_back(i);
        
        int i=0,j=0;
        int dis=INT_MAX;
        
        while(i<map[word1].size() && j<map[word2].size()){
            dis = min(dis,abs(map[word1][i]-map[word2][j]));
            if(map[word1][i]<map[word2][j]) i++;
            else j++;
        }
        
        return dis;
    }
};
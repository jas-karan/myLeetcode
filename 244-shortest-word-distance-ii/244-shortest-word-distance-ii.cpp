class WordDistance {
public:
    int ind=0;
    unordered_map<string,vector<int>>dict;
    
    WordDistance(vector<string>& wordsDict) {
        for(string s:wordsDict) dict[s].push_back(ind++);
    }
    
    int shortest(string word1, string word2) {
        int dis=INT_MAX;
        int i=0,j=0;
        while(i<dict[word1].size() && j<dict[word2].size()){
            dis=min(dis,abs(dict[word1][i]-dict[word2][j]));
            if(dict[word1][i]<dict[word2][j]) i++;
            else j++;
        }
        return dis;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        //remove all the suffices bcoz those can be included in curr string
        for (string w : s)
            for (int i = 1; i < w.size(); ++i)
                s.erase(w.substr(i));
        int res = 0;
        for (string w : s) res += w.size() + 1;
        return res;
    }
};
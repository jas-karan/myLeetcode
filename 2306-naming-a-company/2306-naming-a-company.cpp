class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long res = 0;
    unordered_set<string> s(begin(ideas), end(ideas));
    int cnt[255][255] = {};
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        for (auto &idea : ideas) {
            swap(idea[0], ch);
            if (s.count(idea) == 0)
                ++cnt[idea[0]][ch];
            swap(idea[0], ch);
        }
    }
    for (auto &idea : ideas) {
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            swap(idea[0], ch);
            if (s.count(idea) == 0)
                res += cnt[ch][idea[0]];
            swap(idea[0], ch);
        }
    }
    return res;
        
    }
};
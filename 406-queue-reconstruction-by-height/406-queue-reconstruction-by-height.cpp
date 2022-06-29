class Solution {
private:
    static bool Cmp(vector<int> &p1, vector<int> &p2) {
        return p1[0] == p2[0] ? p1[1] < p2[1] : p1[0] > p2[0];
    }
    
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& ppl) {
        
        
        sort(ppl.begin(), ppl.end(), Cmp);
        vector<vector<int>> res;
        
        for (vector<int> &p : ppl) {
            int idx = p[1];  //how many people in front of curr person?
            
            res.insert(res.begin() + idx, p);
        }
        
        return res;
    }
};
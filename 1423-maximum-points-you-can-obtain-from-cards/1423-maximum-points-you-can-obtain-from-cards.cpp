class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int l=0;
        for(int i=0;i<k;i++) l+=cardPoints[i];
        int res=l;
        int r=0;
        for(int i=0;i<k;i++){
            r+=cardPoints[n-1-i];
            l-=cardPoints[k-1-i];
            res=max(res,l+r);
        }
        
        return res;
    }
};
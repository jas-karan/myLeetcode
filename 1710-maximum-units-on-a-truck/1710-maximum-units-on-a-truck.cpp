class Solution {
public:
    int maximumUnits(vector<vector<int>>& A, int truckSize) {
        int n = A.size();
        
        sort(A.begin(), A.end(), [](vector<int>&a,vector<int>&b){
            return a[1]>b[1];
        });
        
        int unitcnt=0;
        for(auto b:A){
            int cnt = min(truckSize,b[0]);
            unitcnt+= cnt*b[1];
            truckSize-=cnt;
            if(!truckSize) break;
        }
            
        return unitcnt;    
    }
};
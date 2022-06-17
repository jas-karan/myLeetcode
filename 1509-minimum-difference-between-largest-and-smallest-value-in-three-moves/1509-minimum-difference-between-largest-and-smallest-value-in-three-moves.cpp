class Solution {
public:
    int minDifference(vector<int>& A) {
        //if 0 moves ? return max-min
        //if 1 move ? return min(max-min1, max2-min)
        //if 2 moves ? return min(max-min2, max1-min1, max2-min)
        //if 3 moves ? return min(max-min3, max1-min2, max2-min1, max3-min)
        
        int n = A.size();
        if (n < 5) return 0;
        
        sort(A.begin(), A.end());
        return min({A[n - 1] - A[3], A[n - 2] - A[2], A[n - 3] - A[1], A[n - 4] - A[0]});
    }
};
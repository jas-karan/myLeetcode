//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    double waterOverflow(int K, int R, int C) {
        // code here
        vector<vector<double>>pascal(R);
        pascal[0].push_back(K);
        for(int i=1;i<R;i++){
            pascal[i].resize(i+1);
            for(int j=0;j<i;j++){
                double over = max(0.0,pascal[i-1][j]-1);
                pascal[i][j] += over/2.0;
                pascal[i][j+1] += over/2;0;
                pascal[i-1][j] = min(1.0,pascal[i-1][j]);
            }
        }
        for(int j=0;j<pascal[R-1].size();j++) pascal[R-1][j] = min(1.0,pascal[R-1][j]);
        return pascal[R-1][C-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int K,R,C;
        
        cin>>K>>R>>C;

        Solution ob;
        cout << fixed << setprecision(6)<< ob.waterOverflow(K,R,C) << endl;
    }
    return 0;
}
// } Driver Code Ends
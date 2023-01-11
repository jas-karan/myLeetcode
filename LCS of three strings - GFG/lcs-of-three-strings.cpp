//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    int mem[n1+1][n2+1][n3+1];
    memset(mem,0,sizeof(mem));
    
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            for(int k=1;k<=n3;k++){
                if(A[i-1]==B[j-1] && A[i-1]==C[k-1]){
                    mem[i][j][k] = 1+mem[i-1][j-1][k-1];
                }
                else if(A[i-1]==B[j-1]){
                    mem[i][j][k] = max(mem[i][j][k-1],mem[i-1][j-1][k]);
                }
                else if(A[i-1]==C[k-1]){
                    mem[i][j][k] = max(mem[i][j-1][k],mem[i-1][j][k-1]);
                }
                else if(B[j-1]==C[k-1]){
                    mem[i][j][k] = max(mem[i-1][j][k],mem[i][j-1][k-1]);
                }
                else{
                    mem[i][j][k] = max({mem[i][j][k-1],mem[i][j-1][k],mem[i-1][j][k]});
                }
            }
        }
    }
    
    return mem[n1][n2][n3];
}
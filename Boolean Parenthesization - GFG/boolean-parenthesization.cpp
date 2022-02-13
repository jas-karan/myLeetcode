// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(int n, string s){
        // if operator is & then on left and right only true should be there
        // if it is | then true,true false,true or true,false
        // if it is ^ then true,false or false,true
        
        // exp = (LHS) op (RHS)
        // LHS will have lt(count of true) and lf(count of false) ,similarly RHS has rt and rf
        // trueCount and falseCount of exp : depend on op
        // if op is & : then trueCount = lt*rt , falseCount = lf*rt+lt*rf+lf*rf
        // if op is | : then trueCount = lt*rt + lf*rt + lt*rf , falseCount = lf*rf
        // if op is ^ : then trueCount = lt*rf + lf*rt , falseCount = lt*rt + lf*rf
        
        //two dps to store true and false count
        
        string sym="",op="";
        
        for(int i=0;i<n;i++){
            if(i%2==0) sym+=s[i];
            else op+=s[i];
        }
        
        n = sym.length();
        
        int T[n][n],F[n][n];
        
        for(int i=0;i<n;i++){
            T[i][i] = (sym[i]=='T')?1:0;
            F[i][i] = (sym[i]=='F')?1:0;
        }
        
        for(int g=1;g<n;g++){
            
            for(int i=0,j=g; j<n; i++,j++){
                T[i][j]=F[i][j]=0;
                
                for(int k=i;k<j;k++){
                    char oper = op[k];
                    int lt = T[i][k];
                    int lf = F[i][k];
                    int rt = T[k+1][j];
                    int rf = F[k+1][j];
                    
                    if(oper=='&'){
                        T[i][j] += (lt*rt)%1003;
                        F[i][j] += (lf*rt+lt*rf+lf*rf)%1003;
                    }
                    else if(oper=='|'){
                        T[i][j] += (lt*rt + lf*rt + lt*rf)%1003;
                        F[i][j] += (lf*rf)%1003;
                    }
                    else{
                        T[i][j] += (lt*rf + lf*rt)%1003;
                        F[i][j] += (lt*rt + lf*rf)%1003;
                    }
                }
            }
        }
        
        return T[0][n-1]%1003;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
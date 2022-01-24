// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

struct mark{
    int phy;
    int chem;
    int math;
};

class Solution{
    public:
    static bool comp(struct mark a,struct mark b){
        if(a.phy<b.phy) return 1;
        else if(a.phy>b.phy) return 0;
        else{
            if(a.chem>b.chem) return 1;
            else if(a.chem<b.chem) return 0;
            else{
                return a.math<b.math;
            }
        }
    }
    
    void customSort (int phy[], int chem[], int math[], int N)
    {
        // your code here
        struct mark marks[N];
        for(int i=0;i<N;i++){
            marks[i].phy = phy[i];
            marks[i].chem = chem[i];
            marks[i].math = math[i];
        }
        
        sort(marks,marks+N,comp);
        
        for(int i=0;i<N;i++){
            phy[i] = marks[i].phy;
            chem[i] = marks[i].chem;
            math[i] = marks[i].math;
        }
        
    } 
};

// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int phy[n];
		int chem[n];
		int math[n];
		for (int i = 0; i < n; ++i)
			cin >> phy[i] >> chem[i] >> math[i];
        Solution ob;
		ob.customSort (phy, chem, math, n);
		for (int i = 0; i < n; ++i)
			cout << phy[i] << " " << chem[i] << " " << math[i] << endl; 
	}
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends
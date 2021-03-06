// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int shouldPunish (int roll[], int marks[], int n, double avg)
    {
        //first count swaps
        int swaps = 0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(roll[j]>roll[j+1]){
                    swaps++;
                    swap(roll[j],roll[j+1]);
                }
            }
        }
        
        int sum = -2*swaps;  //in an pair there are two students, have to subtract 1 for each
        for(int i=0;i<n;i++) sum+=marks[i];
        double classAvg = (double)sum/n;
        
        if(classAvg>=avg) return 1;
        return 0;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		double avg; cin >> avg;

		int roll[n];
		int marks[n];

		for (int i = 0; i < n; ++i)
			cin >> roll[i];
		for (int i = 0; i < n; ++i)
			cin >> marks[i];
        Solution ob;
		cout << ob.shouldPunish (roll, marks, n, avg) << endl;
	}
}
  // } Driver Code Ends
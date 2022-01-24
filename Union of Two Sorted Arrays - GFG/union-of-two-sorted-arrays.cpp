// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int>arr;
        
        int i=0,j=0,size=-1;
        while(i<n&&j<m){
            if(arr1[i]<=arr2[j]){
                if(size>=0 && arr[size]==arr1[i]){
                    i++;
                    continue;
                }
                arr.push_back(arr1[i++]);
                size++;
            }
            else{
                if(size>=0 && arr[size]==arr2[j]){
                    j++;
                    continue;
                }
                arr.push_back(arr2[j++]);
                size++;
            }
        }
        while(i<n){
            if(size>=0 && arr[size]==arr1[i]){
                i++; continue;
            }
            arr.push_back(arr1[i++]);
            size++;
        }
        while(j<m){
            if(size>=0 && arr[size]==arr2[j]){
                j++; continue;
            }
            arr.push_back(arr2[j++]);
            size++;
        }
        
        return arr;
    }
};

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
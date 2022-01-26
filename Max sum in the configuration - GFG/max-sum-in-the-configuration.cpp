// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int arr[],int n)
{
    //Your code here
    int curr = 0;
    int sum = 0;
    for(int i=0;i<n;i++){ curr+=(i*arr[i]); sum+=arr[i]; }
    int max_sum = curr;
    
    //let arr = [a,b,c,d,e]
    //s0 = a*0 + b*1 + c*2 + d*3 + e*4
    //s1 = b*0 + c*1 + d*2 + e*3 + a*4
    //coeff are decreasing by 1.
    //but for one element whose coeff is 0, it increases to n-1
    //decreasing coeff by one means subtracting the sum of array from current seq.
    //but that will also make coeff of zero coeff element to -1;
    //so we add n*(zero coeff ele)
    
    //rotation sum = prev rotation sum - sum of array + (n)*(zero coeff ele)
    //zero coeff ele will be arr[0], arr[1], ...till arr[n-2]
    
    // total n-1 ways we can rotate an array + original config = n configs total
    for(int i=0;i<n-1;i++){
        int next = curr-sum+(n*arr[i]);
        max_sum = max(max_sum,next);
        curr = next;
    }
    
    return max_sum;
}
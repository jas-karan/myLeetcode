//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int isPossible (string S)
{
    // your code here
    int freq[26]={0};
    for(char c:S) freq[c-'a']++;
    
    bool odd = false;
    for(int i=0;i<26;i++){
        if(freq[i]%2==0) continue;
        if(odd==true) return 0;
        else odd=true;
    }
    return 1;
}
// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        if(str1.length()!=str2.length()) return false;
        
        int freq[26]={0};
        for(char ch:str1) freq[ch-'a']++;
        for(char ch:str2) freq[ch-'a']--;
        
        //similar chars will cancel out frequences
        
        int diff = 0;
        for(int i=0;i<26;i++) if(freq[i]!=0) diff+=abs(freq[i]);
        
        diff = diff/2;  //bcoz for both arrays are counted
        
        if(diff<=k) return true;
        
        return false;
        
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}  // } Driver Code Ends
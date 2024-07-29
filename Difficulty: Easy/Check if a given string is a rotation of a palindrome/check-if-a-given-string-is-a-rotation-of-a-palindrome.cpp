//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int isRotatedPalindrome(string s)
	{
	    // code here
	    int n = s.size();
	    s += s;
	 
	    for(int i=n/2; i<(s.size()-n/2); i++) {
	        int l = i-n/2;
	        int r = i+n/2;
	        if(n%2 == 0) r--;
	        while(l < r and s[l] == s[r]) {
	            l++; r--;
	        }
	        
	        if(l >= r) return 1;
	    }
	    return 0;
	}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.isRotatedPalindrome(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends
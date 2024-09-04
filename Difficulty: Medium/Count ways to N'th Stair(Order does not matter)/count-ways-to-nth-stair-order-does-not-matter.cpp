//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    
		int nthStair(int n){
		    //  Code here
		   int two = n/2;
		   int one = 1;
		   
		   return two+one;
		   
		}
		
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
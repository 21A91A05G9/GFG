//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
      
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    long long int res=1;
		    while(n){
		        if(n&1){
		            res=((res%M)*(x%M))%M;
		            n-=1;
		        }
		        else{
		            x=((x%M)*(x%M))%M;
		            n/=2;
		        }
		    }
		    return res%M;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int nums[], int n)  
	{  
	    // Your code goes here
	    vector<int>dp(n, 0);
	    int maxi = nums[0];
	    dp[0] = maxi;
	    for(int i=1; i<n; i++) {
	        dp[i] = nums[i];
	        for(int j=0; j<i; j++) {
	            if(nums[i] > nums[j]) {
	                dp[i] = max(dp[i], nums[i]+dp[j]);
	            }
	        }
	        
	        maxi = max(maxi, dp[i]);
	    }
	    
	    return maxi;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
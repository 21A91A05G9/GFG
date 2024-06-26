//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int solve(int i, vector<pair<double,pair<int,int>>>&v, int w, vector<vector<int>>&dp) {
        if(i < 0) return 0;
        if(w < 0) return 0;
        int p=0, np=0;
        if(dp[i][w] != -1) return dp[i][w];
        if((w-v[i].second.first) >= 0) p = v[i].second.second + solve(i-1, v, w-v[i].second.first, dp);
        np = solve(i-1, v, w, dp);
        return dp[i][w] = max(p, np);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<pair<double,pair<int,int>>>v;
       vector<vector<int>>dp(n+1,vector<int>(W+1, -1));
       
       for(int i=0; i<n; i++) {
           double frac = (val[i]/(1.0*wt[i]));
           v.push_back({frac,{wt[i], val[i]}});
       }
       sort(v.begin(), v.end());
       
       return solve(n-1, v, W, dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
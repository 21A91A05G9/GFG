//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int solve(int i,int coins[], int N, int sum,vector<vector<long long int>>&dp) {
        if(i == N) return 0;
        if(sum == 0) return 1;
        if(sum < 0) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        
        long long int p = solve(i,coins,N,sum-coins[i],dp);
        long long int np = solve(i+1,coins,N,sum,dp);
        return dp[i][sum] = p + np;
        
    }
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long int>>dp(N+1,vector<long long int>(sum+1,-1));
        return solve(0,coins,N,sum,dp);
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    int solve(int i, int coins[], int sum, vector<vector<int>>&dp) {
       if(i < 0) {
        if(sum == 0) return 0;
        if(sum%20 == 0 || sum%24 == 0 || sum == 2024) return 1;
        return 0;
       }
       if(dp[i][sum] != -1) return dp[i][sum];
       int newSum = sum+coins[i];
       if(solve(i-1, coins, sum+coins[i], dp)) return dp[i][sum] = 1;
       if(solve(i-1, coins, sum, dp)) return dp[i][sum] = 1;
       return 0;
    }
    int isPossible(int N , int coins[]) 
    {
        vector<vector<int>>dp(N, vector<int>(2025, -1));
        int sum = 0;
        return solve(N-1, coins, 0, dp);
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, unordered_map<int,int>&mp, vector<int>&dp) {
        
       
        if(i > 30) return 100;
        if(i == 30) return 0;
        
        if(dp[i] != -1) return dp[i];
        if(mp.find(i) != mp.end()) {
            int temp = mp[i];
            if(temp < i) return 100;
            else i = temp;
        }
        
        int mini = INT_MAX;
        for(int j=1; j<=6; j++) {
            int step = 1+solve(i+j, mp, dp);
            mini = min(mini, step);
        }
        return dp[i] = mini;
    }
    int minThrow(int N, int arr[]){
        // code here
        unordered_map<int ,int>mp;
        for(int i=0; i<2*N; i+=2) {
            mp[arr[i]] = arr[i+1];
        }
        vector<int>dp(31, -1);
        return solve(1, mp, dp);
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(int i, vector<int>arr, int sum, vector<vector<int>>&dp ) {
        if(sum == 0) return true;
        if(i >= arr.size() || sum < 0) return false;
        if(dp[i][sum] != -1) return dp[i][sum];
        
        return dp[i][sum] = solve(i+1, arr, sum-arr[i], dp) || solve(i+1, arr, sum, dp);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>>dp(arr.size(), vector<int>(sum+1, -1));
        sort(arr.begin(), arr.end());
        return solve(0, arr, sum, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
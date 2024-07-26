//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int j, string s, int arr[], vector<vector<int>>&dp,
                vector<vector<string>>&res) {
        if(i == j) {
            char ch = char(65+i);
            s = ch;
            return 0;
        }
        if(dp[i][j] != -1) {
            s = res[i][j];
            return dp[i][j];
        }
        
        string a, b, str;
        int maxi = INT_MAX;
        for(int k=i; k<j; k++) {
           int step1 = solve(i, k, a, arr, dp, res);
           int step2 = solve(k+1, j, b, arr, dp, res);
           int step3 = arr[i-1]*arr[k]*arr[j];
           
           if((step1+step2+step3) < maxi) {
               maxi = step1+step2+step3;
               str = '(' + a + b + ')';
           }
        }
        s = str;
        res[i][j] = s;
        return dp[i][j] = maxi;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        string s;
        vector<vector<string>>res(N, vector<string>(N, ""));
        vector<vector<int>>dp(N, vector<int>(N, -1));
        // cout<<res[1][N-1];
        return solve(1, N-1, s, arr, dp, res);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
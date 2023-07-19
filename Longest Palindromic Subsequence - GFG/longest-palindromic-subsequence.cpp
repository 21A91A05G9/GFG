//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        int n=A.size();
        string B;
        for(int i=n-1;i>=0;i--){
            B+=A[i];
        }
        vector<vector<int>>v(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(A[j-1]==B[i-1]){
                    v[i][j]=1+v[i-1][j-1];
                }
                else{
                    v[i][j]=max(v[i][j-1],v[i-1][j]);
                }
            }
        }
        return v[n][n];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int solve(int i, int j, string &s, vector<vector<int>>&dp) {
	        if(i >= s.size() or j >= s.size()) return 0;
	        if(dp[i][j] != -1) return dp[i][j];
	        if(i != j && s[i] == s[j]) return dp[i][j] = 1 +solve(i+1, j+1, s, dp);
	        else {
	            int a = solve(i+1, j, s, dp);
	            int b = solve(i, j+1, s, dp);
	            return dp[i][j] = max(a, b);
	        }
	    }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    vector<vector<int>>dp(str.size(), vector<int>(str.size(), -1));
		    return solve(0, 1, str, dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
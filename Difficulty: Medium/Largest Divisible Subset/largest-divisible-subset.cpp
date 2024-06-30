//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& nums) {
        // Code here
        sort(nums.begin(), nums.end());
        int maxi = 0, lastInd = 0;
        vector<int>v, dp(n, 1), hash(n);
        
        for(int i=0; i<n; i++) {
            
            hash[i] = i;
            for(int j=0; j<i; j++) {
                if((nums[i] % nums[j]) == 0 and (dp[j] + 1) > dp[i]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
                
                if(maxi < dp[i]) {
                    maxi = dp[i];
                    lastInd = i;
                }
            }
        }
       
        while(hash[lastInd] != lastInd) {
            v.push_back(nums[lastInd]);
            lastInd = hash[lastInd];
        }
        v.push_back(nums[lastInd]);
        
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends
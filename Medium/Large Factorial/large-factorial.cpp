//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution{
public:
    vector<long long> factorial(vector<long long> a, int n) {
        
        vector<long long>ans;
        long long ma = 0;
        for(int i=0; i<n; i++) {
            ma = max(ma,a[i]);
        }
        vector<int>v(ma+1,0);
        v[0] = 1;
        int m = 1e9+7;
        long long res = 1;
        for(int k=1; k<=ma; k++) {
            res = (res%m * k%m )%m;
            v[k] = res;
        }
        ;
        for(int i=0; i<a.size(); i++) {
            ans.push_back(v[a[i]]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<long long> res = ob.factorial(a, n);
        for (i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
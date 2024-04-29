//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        int j = 0;
        int ma=0, cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i] == 1) cnt++;
            else {
                m--;
                cnt++;
            }
            
            while(m < 0) {
                if(arr[j] == 0) m++;
                j++;
                cnt--;
                
            }

            ma = max(ma,cnt);
         
        }
        return ma;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
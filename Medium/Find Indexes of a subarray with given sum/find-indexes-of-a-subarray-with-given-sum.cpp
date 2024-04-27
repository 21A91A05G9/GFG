//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        vector<int>v;
        int sum = 0;
        int ind1 = 0, ind2 = 0, j = 0, i = 0;
        if(s == 0) {
            for(int i=0; i<n; i++) {
                if(arr[i] == 0) {
                    v.push_back(i+1);
                    v.push_back(i+1);
                    return v;
                }
            }
            v.push_back(-1);
            return v;
        }
        
        
        for(i=0; i<n; i++){
            
            if(sum == s ) {
                ind2 = i-1;
                break;
            }
            sum += arr[i];
          
            while(sum > 0 and sum > s) {
                sum -= arr[j++];
                ind1 = j;
            }
           
        }
        if(i == n) ind2 = n-1;
        if(sum == s) {
            v.push_back(ind1+1);
            v.push_back(ind2+1);
        }
        else v.push_back(-1);
        return v;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
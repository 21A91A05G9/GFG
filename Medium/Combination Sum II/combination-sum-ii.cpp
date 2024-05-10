//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    void solve(int i,vector<int>arr, int n, int k,vector<int>&v, vector<vector<int>>&ans) {
        // cout<<k<<" ";
        if(k == 0) {
            auto it = find(ans.begin(),ans.end(),v);
            if(it == ans.end()) ans.push_back(v);
            return;
        }
        if(i == n) return;
        if(k < 0) return;
        
        for(int j=i;j<n;j++) {
            if((k-arr[j]) < 0) break;
            v.push_back(arr[j]);
            solve(j+1,arr,n,k-arr[j],v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        vector<vector<int>>ans;
        vector<int>v;
        sort(arr.begin(),arr.end());
        solve(0,arr,n,k,v,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
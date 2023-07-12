//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void com(vector<int>&A,int t,int i,int N,int sum,vector<int>&v,vector<vector<int>>&ans){
        if(sum==t) {
            //cout<<"p";
            auto it=find(ans.begin(),ans.end(),v);
            if(it==ans.end()) ans.push_back(v);
            return;  
        }
        
        for(int j=i;j<N;j++){
            if((sum+A[j])>t) break;
            v.push_back(A[j]);
            com(A,t,j+1,N,sum+A[j],v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> CombinationSum2(vector<int> A,int n,int k)
    {
        //code here
        vector<int>v;
        vector<vector<int>>ans;
        
        int sum=0;
        sort(A.begin(),A.end());
        com(A,k,0,A.size(),sum,v,ans);
        
        
        return ans;
        
//         11 7
// 28 16 94 3 13 70 31 88 33 12 69
        
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
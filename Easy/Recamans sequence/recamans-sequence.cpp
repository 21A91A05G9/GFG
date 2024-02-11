//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        long long int i=1;
        vector<int>v;
        v.push_back(0);
        map<int,int>mp;
        long long int prev=0;
        while(i<=n){
            if((prev-i)>0){
                prev=prev-i;
                if(mp[prev]>=1) prev=i+i+prev;
            }
            else{
                prev=prev+i;
            }
            mp[prev]++;
            v.push_back(prev);
            i++;
        }
        return v;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
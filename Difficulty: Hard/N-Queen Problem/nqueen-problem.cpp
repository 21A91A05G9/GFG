//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int i, int n, vector<int>&col, vector<int>&leftDia, 
    vector<int>&rightDia, vector<int>v, vector<vector<int>>&ans) {
        if(i == n) {
            ans.push_back(v);
            return;
        }
        
        for(int j=0; j<n; j++) {
            if(col[j] == 0 && leftDia[i+j] == 0 && rightDia[i-j+n] == 0) {
                col[j] = 1;
                leftDia[i+j] = 1;
                rightDia[i-j+n] = 1;
                v.push_back(j+1);
                
                solve(i+1, n, col, leftDia, rightDia, v, ans);
                
                v.pop_back();
                col[j] = 0;
                leftDia[i+j] = 0;
                rightDia[i-j+n] = 0;
                
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<int>v;
        vector<vector<int>>ans;
        
        vector<int>col(n, 0);
        vector<int>leftDia(2*n, 0);
        vector<int>rightDia(2*n, 0);
        
        solve(0, n, col, leftDia, rightDia, v, ans);
        return ans;
        
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
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
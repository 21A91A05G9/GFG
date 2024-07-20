//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    int solve(int i, int j, int p[], string &s, vector<vector<int>>&dp, vector<vector<string>>&str) {
        if(i == j) {
            s = char(i+64);
            return 0;
        }
        if(dp[i][j] != -1) {
            s = str[i][j];
            return dp[i][j];
        }
        int mini = INT_MAX;
        string a, b, ans;
        for(int k=i; k<j; k++) {
            int step1 = solve(i, k, p, a, dp, str);
            int step2 = solve(k+1, j, p, b, dp, str);
            int step3 = p[i-1]*p[k]*p[j] + step1 + step2;
            
            if(step3 < mini) {
                mini= step3;
                ans = "(" + a + b + ")";
            }
        }
        s = ans;
        str[i][j] = s;
        return dp[i][j] = mini;
    }
    string matrixChainOrder(int p[], int n){
        // code here
        string s;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        vector<vector<string>>str(n, vector<string>(n, ""));
        int flag = solve(1, n-1, p, s, dp, str);
        return str[1][n-1];
    }
};

//{ Driver Code Starts.

int get(int p[],int n)
{
    int m[n][n],ans = 1e9; 
    for (int i = 1; i < n; i++)
        m[i][i] = 0; 
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n-L+1; i++){ 
            m[i][i + L - 1] = INT_MAX; 
            for (int k = i; k <= i + L - 2; k++){ 
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i-1] * p[k] * p[i + L - 1]; 
                if (q < m[i][i + L - 1])
                { 
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int find(string s,int p[])
{
    vector<pair<int,int>> arr;
    int ans = 0;
    for(auto t:s)
    {
        if(t=='(')
        {
            arr.push_back({-1,-1});
        }
        else if(t==')')
        {
            pair<int,int> b=arr.back();
            arr.pop_back();
            pair<int,int> a=arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first,b.second});
            ans += a.first*a.second*b.second;
        }
        else 
        {
            arr.push_back({p[int(t-'A')],p[int(t-'A')+1]});
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
        {
            cin>>p[i];
        }
        Solution ob;
        string result = ob.matrixChainOrder(p, n);
        if(find(result,p)==get(p,n))
        {
            cout<<"True"<<endl;
        }
        else
        {
            cout<<"False"<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i, int j, string s, vector<vector<int>>&m, int n, vector<string>&ans, vector<vector<int>>&ch) {
        
        if(i==(n-1) and j==(n-1)) {
            
            ans.push_back(s);
            return;
        }
        
        if(ch[i][j] == 1 or m[i][j] == 0) return;
        
        ch[i][j] = 1;
        
        vector<int>row{1,0,-1,0};
        vector<int>col{0,1,0,-1};
        
        vector<char>dir{'D', 'R', 'U', 'L'};
        
        for(int k=0; k<4; k++) {
            
            if((i+row[k]) >=0 and (i+row[k]) < n and (j+col[k]) >= 0 and (j+col[k]) < n) {
                s += dir[k];
                
                solve(i+row[k], j+col[k], s, m, n, ans, ch);
                s.pop_back();
            }
            
        }
        
        ch[i][j] = 0;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        if(m[0][0] == 0 or m[n-1][n-1] == 0) return ans;
        vector<vector<int>>ch(n, vector<int>(n, 0));
        solve(0, 0, "", m, n, ans, ch);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
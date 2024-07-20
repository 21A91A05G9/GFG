//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& ch,
                string s, vector<string>&v) {
                    
        if(i >= mat.size() or j >= mat[0].size()) return;
        if(mat[i][j] == 0 or ch[i][j] == 1) return;
        if(i == mat.size()-1 and j == mat[0].size()-1)  v.push_back(s);
        
        ch[i][j] = 1;
        
        vector<int>row{1, -1, 0, 0};
        vector<int>col{0, 0, 1, -1};
        vector<char>dir{'D', 'U', 'R', 'L'};
        for(int k=0; k<4; k++) {
            s += dir[k];
            solve(i+row[k], j+col[k], mat, ch, s, v);
            s.pop_back();
        }
        ch[i][j] = 0;
                    
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<vector<int>>ch(mat.size(), vector<int>(mat[0].size(), 0));
        vector<string>v;
        solve(0, 0, mat, ch, "", v);
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void solve(int i, int j, vector<vector<int>>&mat, vector<vector<int>>&ch
        , string &s, vector<string>&ans) {
        
        
        if(i == (mat.size()-1) && j == (mat[0].size()-1)) {
            ans.push_back(s);
            return;
        } 
        
        
                
        vector<int>row{-1, 1, 0, 0}, col{0, 0, -1, 1};
        vector<char>dir{'U', 'D', 'L', 'R'};
        
        for(int k=0; k<4; k++) {
            int x = row[k] + i;
            int y = col[k] + j;
            
            if(x >= 0 and x < mat.size() and y >= 0 and y < mat[0].size()
                and ch[x][y] == 0 and mat[x][y] == 1) {
                s += dir[k];
                ch[x][y] = 1;
                solve(x, y, mat, ch, s, ans);
                ch[x][y] = 0;
                s.pop_back();
            }
            
            
        }
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string>ans;
        if(mat[0][0] == 0 || mat[mat.size()-1][mat[0].size()-1] == 0) return ans;
        vector<vector<int>>ch(mat.size(), vector<int>(mat[0].size(), 0));
        
        string s;
        ch[0][0] = 1;
        solve(0, 0, mat, ch, s, ans);
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
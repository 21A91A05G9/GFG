//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int i,int j,vector<vector<int>>&ch,vector<vector<char>>& grid){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]=='0' or ch[i][j]==1) return;
        ch[i][j]=1;
        
        dfs(i-1,j,ch,grid);
        dfs(i-1,j+1,ch,grid);
        dfs(i,j+1,ch,grid);
        dfs(i+1,j+1,ch,grid);
        dfs(i+1,j,ch,grid);
        dfs(i+1,j-1,ch,grid);
        dfs(i,j-1,ch,grid);
        dfs(i-1,j-1,ch,grid);
    }
   
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size(),cnt=0;
        vector<vector<int>>ch(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(ch[i][j]==0 and grid[i][j]=='1'){
                    dfs(i,j,ch,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
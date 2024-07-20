//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>>ch(n, vector<int>(m, 0));
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
              
                if(grid[i][j] == '1') {
                    queue<pair<int, int>>q;
                    q.push({i,j});
                    while(q.size()>0) {
                        int ind1 = q.front().first, ind2 = q.front().second;
                        q.pop();
                        vector<int>row{-1, -1, -1, 0, 0, 1, 1, 1};
                        vector<int>col{-1, 0, 1, -1, 1, -1, 0, 1};
                        
                        for(int k=0; k<8; k++) {
                            int x = row[k] + ind1, y = col[k] + ind2;
                            if(x >= 0 and x < n and y >=0  and y < m and grid[x][y] == '1') {
                                grid[x][y] = '0';
                                q.push({x,y});
                            
                            }
                            
                        }
                    }
                    ans++;
                    
                }
            }
        }
        return ans;
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
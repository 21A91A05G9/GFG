//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(int i, int j, vector<vector<int>>& matrix) {
       

        vector<int>row{-1, 1, 0, 0};
        vector<int>col{0, 0, -1, 1};
        
        for(int k=0; k<4; k++) {
            int x = i+row[k], y = j+col[k];
            if(x>=0 and y>=0 and x< matrix.size() and y<matrix[0].size() and
                matrix[x][y] == 1) {
                matrix[x][y] = 0;
                dfs(x, y, matrix);
            }
        }
    }
    
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if((i == 0 or i == (N-1) or j == 0 or j == (M-1) ) 
                and matrix[i][j] == 1){
                    matrix[i][j] = 0;
                    dfs(i, j, matrix);
                } 
            }
        }
        
        int ans = 0;
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(matrix[i][j] == 1) {
                    matrix[i][j] = 0;
                    dfs(i, j, matrix);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends
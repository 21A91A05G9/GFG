//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    
    //Function to find a solved Sudoku
    bool isSafe(int i, int j, int k, int grid[N][N]) {
        for(int ind=0; ind<9; ind++) {
            if(grid[i][ind] == k or grid[ind][j] == k) return false;
        }
        
        int l=(i/3)*3, r=(j/3)*3;
        
        for(int ind1=0; ind1<3; ind1++) {
            for(int ind2=0; ind2<3; ind2++) {
                if(grid[l+ind1][r+ind2] == k) return false;
            }
        }
        return true;
    }
    
    bool solve(int i, int j, int grid[N][N]){
        if(i == 9) return true;
        if(j == 9) return solve(i+1, 0, grid);
        
        if(grid[i][j] == 0) {
            for(int k=1; k<=9; k++) {
                if(isSafe(i, j, k, grid)) {
                    grid[i][j] = k;
                    if(solve(i, j+1, grid)) return true;
                    grid[i][j] = 0;
                }
            }
            return false;
        }
        else {
            if(solve(i, j+1, grid)) return true;
            return false;
        }
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        return solve(0, 0, grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int M, int N, vector<vector<int>> Mat) {
        // code here
        int t=0, l=0, d=(M-1), r=(N-1);
        
        while(t<d and l<r) {
            int temp = Mat[t+1][l];
            for(int i=l; i<=r; i++){
                int curr = Mat[t][i];
                Mat[t][i] = temp;
                temp = curr;
            }
            t++;
           
            for(int i=t; i<=d; i++){
                int curr = Mat[i][r];
                Mat[i][r] = temp;
                temp = curr;
            }
            r--;
           
            for(int i=r; i>=l; i--){
                int curr = Mat[d][i];
                Mat[d][i] = temp;
                temp = curr;
            }
            d--;
        
            for(int i=d; i>=t; i--){
                int curr = Mat[i][l];
                Mat[i][l] = temp;
                temp = curr;
   
            }
            
            l++;
        }
        return Mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(N, M, Mat);
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends
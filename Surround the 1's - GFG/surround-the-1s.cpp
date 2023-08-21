//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& m) {
        // Code here
        int ans=0,cnt=0;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                cnt=0;
                if(m[i][j]==1){

                    if(i-1>=0 and m[i-1][j]==0) cnt++;
                    if(j-1>=0 and m[i][j-1]==0) cnt++;
                    if(i+1<m.size() and m[i+1][j]==0) cnt++;
                    if(j+1<m[0].size() and m[i][j+1]==0) cnt++;
                    if(i-1>=0 and j-1>=0 and m[i-1][j-1]==0) cnt++;
                    if(i-1>=0 and j+1<m[0].size() and m[i-1][j+1]==0) cnt++;
                    if(i+1<m.size() and j+1<m[0].size() and m[i+1][j+1]==0) cnt++;
                    if(i+1<m.size() and j-1>=0 and m[i+1][j-1]==0) cnt++;
                }

                if(cnt%2==0 and cnt!=0) ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
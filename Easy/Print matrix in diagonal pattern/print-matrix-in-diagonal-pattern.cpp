//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         int i=0,j=0,flag=0,n=mat.size();
         vector<int>v;
         while(i>=0 and j>=0 and i<n and j<n){
             
             if(flag==1){
                while(i<n and j>=0){
                   
                    v.push_back(mat[i][j]);
                    i++;
                    j--;
                    // cout<<i<<','<<j<<"\n";
                 }
                 if(j<0 and i<n) j++;
                 else {i--; j+=2;}
        
                //  cout<<i<<','<<j<<"\n";
                 flag=0;
             }
             else{
                
                while(i>=0 and j<n){
                    v.push_back(mat[i][j]);
                    i--;
                    j++;
                    // cout<<i<<','<<j<<"\n";
                }
                if(i<0 and j<n) i++;
                else {i+=2; j--; }
                // cout<<i<<','<<j<<"\n";
                flag=1;
             }
         }
         return v;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends
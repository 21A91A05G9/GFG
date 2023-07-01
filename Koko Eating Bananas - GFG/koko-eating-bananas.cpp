//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int Solve(int N, vector<int>& arr, int H) {
     
        int i=1,j=0,val=-1;
        for(int i=0;i<N;i++){
            if(arr[i]>j){
                j=arr[i];
            }
            
        }
        while(i<=j){
            
            int m=(i+j)/2;

            int cnt=0;
            for(int i=0;i<N;i++){
                if(arr[i]%m!=0){
                    cnt+=1;
                }
                cnt+=arr[i]/m;
                
                
            }
            while(cnt==H){
               
                val=m;
                m-=1;
                cnt=0;
                for(int i=0;i<N;i++){
                    if(arr[i]%m!=0){
                        cnt+=1;
                    }
                    cnt+=arr[i]/m;
               }
               if(cnt!=H) return val;
            }

            if(cnt>H){
               
                i=m+1;
            }
            else if(cnt<H){
                
                j=m-1;
            }
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
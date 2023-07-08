//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &f) {
        int a=-1,b=-1,p=0,q=0,s=0,m=0,n=f.size();
        for(int i=0;i<n;i++){
            if(a==-1){
                a=f[i];
                p=1;
            }
            else if(f[i]==a){
                p++;
            }
            else if(b==-1){
                b=f[i];
                q=1;
            }
            else if(b==f[i]){
                q++;
            }
            else{
                while(p>0 and q>0){
                    if(f[s]==a) p--;
                    else q--;
                    s++;
                }
                if(p==0) { a=f[i]; p=1; }
                else { b=f[i]; q=1; }
            }
            m=max(m,(p+q));
        }
        return m;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends
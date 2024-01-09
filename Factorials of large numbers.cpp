//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int>v(100000,0);
        if(N==1){
            vector<int>v{1};
            return v;
        }
        int n=2;
        v[0]=1;
        int i=1;
        int j;
        while(n<=N){
            int c=0;
            for(j=0;j<i;j++){
                int val=(n*v[j])+c;
                v[j]=(val)%10;
                c=val/10;
            }
            while(c>=1){
                v[j]=c%10;
                c/=10;
                i=j+1;
                j++;
            }
            // for(int i=0;i<=j;i++){
            //     cout<<v[i]<<" ";
            // }
            // cout<<"\n";
            n++;
            
        }
        vector<int>vv;
        for(int k=(i-1);k>=0;k--){
            vv.push_back(v[k]);
        }
        return vv;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

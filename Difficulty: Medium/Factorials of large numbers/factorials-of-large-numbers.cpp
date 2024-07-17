//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int multiply(int x, vector<int>&res, int N) {
        int carry = 0;
        for(int i=0; i<N; i++) {
            int prod = res[i] * x + carry;
            
            res[i] = prod%10;
            carry = prod/10;
        }
        while(carry) {
            res[N++] = carry%10;
            carry /= 10;
        }
        
        return N;
    }
    vector<int> factorial(int N){
        // code here
        vector<int>res(100000, 0);
        res[0] = 1;
        
        int size = 1;
        
        
        for(int i=2; i<=N; i++) {
            size = multiply(i, res, size);
        }
        
        vector<int>ans;
        for(int i=size-1; i>=0; i--) {
            ans.push_back(res[i]);
        }
        
        return ans;
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
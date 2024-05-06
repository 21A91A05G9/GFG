//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution{
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int a = INT_MAX, m = INT_MIN, n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0; i<(n-2); i++) {
            int l=i+1, r=(n-1);
            while(l < r) {
                
                int val = arr[i]+arr[l]+arr[r];
               
                if(abs(val-target) < a) {
                    m = val;
                    a = abs(val-target);
                   
                }
                else if(abs(val-target) == a) {
                    m = max(val, m);
                }
                
                if(val > target) r--;
                else l++;
                
            }
        }
        return m;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        int n,target;
        cin >> n >> target;
        
        vector<int> vec(n);
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}

//Position this line where user code will be pasted.

// } Driver Code Ends
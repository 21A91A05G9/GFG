//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int a[], int n){
        // code here
        long long l=0, r=n-1, lmax=0, rmax=0, ans=0;
        while(l <= r) {
            if(a[l] <= a[r]) {
                if(a[l] >= lmax) lmax = a[l];
                else ans += (lmax-a[l]);
                l++;
            }
            else {
                if(a[r] >= rmax) rmax = a[r];
                else ans += (rmax-a[r]);
                r--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
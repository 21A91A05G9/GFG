//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        long long l=0, r=n-1, lmax=0, rmax=0, sum=0;
        
        while(l < r) {
            if(arr[l] <= arr[r]) {
                if(lmax < arr[l]) lmax = arr[l];
                else sum += lmax - arr[l++];
            }
            else {
                if(rmax < arr[r]) rmax = arr[r];
                else sum += rmax - arr[r--];
            }
        }
        return sum;
        
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
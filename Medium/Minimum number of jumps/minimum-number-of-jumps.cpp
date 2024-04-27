//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(n == 1) return 0;
        if(arr[0] >= (n-1)) return 1;
        if(arr[0] == 0) return -1;
        
        int step = arr[0], m = arr[0], ind = 0, cnt = 1;
        for(int i=1; i<n; i++) {
            if(m < arr[i]+i) {
                m = arr[i]+i;
                ind = i;
            }
            step--;
            if(m == (n-1)) {
                cnt++;
                break;
            }
            if(step == 0) {
                step = arr[ind];
                if(ind < i) step -= (i-ind);
                if(step == 0) {
                    cnt = -1;
                    break;
                }
                cnt++;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
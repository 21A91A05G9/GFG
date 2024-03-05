//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        vector<int>mi(n,0),ma(n,0);
        int m=0;
        mi[0]=a[0]; ma[n-1]=a[n-1];
        for(int i=1;i<n;i++){
            mi[i]=min(a[i],mi[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            ma[i]=max(a[i],ma[i+1]);
        }
        
        int i=0,j=0;
        while(i<n and j<n){
            if(mi[i]<=ma[j]) {
                m=max(m,j-i);
                j++;
            }
            else i++;
        }
        return m;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int a[], int n, int x) {
	    // code hereint count(int a[], int n, int x) {
	    // code here
	    int i=0,j=n-1;
        while(i<=j)
        {
            int m=(i+j)/2;
            if(a[m]==x)
            {
                int mi=m,mj=m;
                while(mi>=0 and a[mi]==x)
                {
                    i=mi;
                    mi--;
                }
                while(mj<n and a[mj]==x)
                {
                    j=mj;
                    mj++;
                }
                return j-i+1;
            }
            else if(a[m]>x) j=m-1;
            else i=m+1;
        }
        return 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    


    long long int cnt = 0;
    void mergeSort(int l, int m, int r, long long arr[]) {
        vector<long long>v;
        
        int i=l, j=m;
        while(i<m and j<=r) {
            if(arr[i] <= arr[j]) v.push_back(arr[i++]);
            else {
                cnt += (m-i);
                v.push_back(arr[j++]);
            }
        }
        while(i<m) {
            v.push_back(arr[i++]);
        }
        while(j<=r) {
            v.push_back(arr[j++]);
        }
        
        for(auto e:v) {
            arr[l++] = e;
        }
    }
    void merge(int  i,int j,long long arr[]) {
        if(i >= j) return;
        int m = (i+j)/2;
        merge(i,m,arr);
        merge(m+1,j,arr);
        mergeSort(i,m+1,j,arr);
      
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        merge(0,N-1,arr);
        return cnt;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
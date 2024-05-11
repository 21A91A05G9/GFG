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
    void mergeSort(long long arr[], int i, int m, int j) {
        vector<long long>b;
        
        
        int ind1 = i, ind2 = m;
        while(ind1<m and ind2 <= j) {
            if(arr[ind1] <= arr[ind2]) b.push_back(arr[ind1++]);
            else {
                b.push_back(arr[ind2++]);
                cnt += (m-ind1);
            }
        }
        while(ind1<m) b.push_back(arr[ind1++]);
        while(ind2<=j) b.push_back(arr[ind2++]);
        
        int k1=0;
        for(int k=i; k<=j; k++) {
            arr[k] = b[k1++];
        }
    }
    void merge(long long arr[], int i, int j) {
        if(i < j) {
            int m =(i+j)/2;
            merge(arr,i,m);
            merge(arr,m+1,j);
            mergeSort(arr,i,m+1,j);
        }
      
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        merge(arr,0,N-1);
       
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
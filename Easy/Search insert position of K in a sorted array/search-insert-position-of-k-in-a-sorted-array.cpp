//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        // code here
        if(k < Arr[0]) return 0;
        if(k > Arr[N-1]) return N;
        int i=0, j=N-1;
        while(i<j) {
            int m = (i+j)/2;
            if(Arr[m] == k) return m;
            else if(Arr[m] < k) i++;
            else j--;
        }
       
        return j;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
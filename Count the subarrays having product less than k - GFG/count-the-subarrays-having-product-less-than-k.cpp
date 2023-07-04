//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
        long long s=1,j=0,i=0,ans=0;
        for(i=0;i<n;i++){
            if(arr[i]>=k){
                int val=(i-j);
                //cout<<val<<" ";
                ans+=(val*(val+1)/2);
                s=1;
                //cout<<i<<" ";
                j=i+1;
                continue;
            }
            s*=arr[i];
            int val1=i-j,f=0;
            //cout<<j<<" "<<i<<" ";
            while(s>=k and s!=1){
                s/=arr[j];
                j++;
                f=1;
            }
            if(f==1 and j<=i){
                int val2=i-j;
               
                ans+=(val1*(val1+1)/2)-(val2*(val2+1)/2);
            }
           
        }
      
        if(s<k){
            int val=i-j;
            ans+=(val*(val+1)/2);
        }
       
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
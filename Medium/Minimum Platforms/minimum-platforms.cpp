//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
   
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int,int>>t;
    	for(int i=0; i<n; i++) t.push_back({arr[i],dep[i]});
    	sort(t.begin(),t.end());
    	int cnt = 1;
    	priority_queue<int,vector<int>,greater<int>> p;
    	p.push(t[0].second);
    	
    	for(int i=1;i<n;i++) {
    	   
    	   if( p.top() >= t[i].first) {
    	       cnt++;
    	   }
    	   else{
    	       p.pop();
    	   }
    	 
    	   p.push(t[i].second);
    	   
    	}

    	return cnt;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends
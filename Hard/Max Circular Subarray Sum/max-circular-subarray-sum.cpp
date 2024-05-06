//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        
        int m1 = INT_MIN, m2 = INT_MAX, s1 = 0, s2 = 0, s = 0;
        for(int i=0; i<num; i++) {
            s += arr[i];
            
            s1 += arr[i];
            m1 = max(m1, s1);
            if(s1 < 0) s1 = 0;
            
            s2 += arr[i];
            m2 = min(m2, s2);
            if(s2 > 0) s2 = 0;
            // cout<<m1<<" "<<m2<<" "<<s;
        }
        if(m2 == s) return m1;
        else return max(m1, s-m2);
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
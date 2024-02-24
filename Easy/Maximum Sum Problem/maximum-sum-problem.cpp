//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
      
        int maxSum(int n)
        {
            //code here
            if(n<=0) return 0;
            
            int a=maxSum((int)n/2);
            int b=maxSum((int)n/3);
            int c=maxSum((int)n/4);

            if(n>=(a+b+c)) return n;
            
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
 
class Solution
{
    public:
    // Function for finding maximum AND value.
    int maxAND (int arr[], int N)
    {
        // Your code here
        int m=0;
        vector<int>v;
        for(int i=0;i<N;i++){
            v.push_back(arr[i]);
            m=max(m,arr[i]);
        }
        int p=log2(m);
        //cout<<p;
        while(p>=0){
            vector<int>v1,v2;
            for(int i=0;i<v.size();i++){
                if(v.size()==2) break;
                if((v[i]>>p)&1){
                    v1.push_back(v[i]);
                }
                else{
                    v2.push_back(arr[i]);
                }
            }
            if(v1.size()>1){
                v.assign(v1.begin(), v1.end());
            } 
            p--;
        }
        if(v.size()<=1) return 0;
        else{
            //for(auto e:v) cout<<e<<" ";
            return v[0]&v[1];
        }
    }
};

//{ Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
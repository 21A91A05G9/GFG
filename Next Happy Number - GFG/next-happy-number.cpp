//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int nextHappy(int N){
        // code herewho
        N+=1;
        int t=N;
        //cout<<t<<" ";
        while(t>9){
            int s=0;
            while(t>0){
                int d=t%10;
                s+=(d*d);
                t/=10;
            }
            t=s;
        }
        if(t==1 or t==7){
            return N;
        }
        else{
            nextHappy(N);
        }
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
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
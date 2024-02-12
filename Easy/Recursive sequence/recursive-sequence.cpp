//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long int m=1e9+7;
    long long findSeq(int i,int cnt,int n){
        if(cnt>n) return 0;
        long long int s=1,temp=cnt;
        while(cnt--){
            s=(s%m*i%m)%m;
            i++;
        }
        return (s%m+findSeq(i,temp+1,n)%m)%m;
    }
    long long sequence(int n){
        
        return findSeq(1,1,n);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
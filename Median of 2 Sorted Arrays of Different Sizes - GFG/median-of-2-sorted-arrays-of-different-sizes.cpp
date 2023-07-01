//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& a1, vector<int>& a2)
    {
        // Your code goes here
        int i=0,j=0,k;
        vector<int>v;
        int n=a1.size(),m=a2.size();
        k=(n+m)/2; k+=1;
        //cout<<k;
        while(i<a1.size() and j<a2.size() and v.size()<=(k-1)){
            if(a1[i]<=a2[j]){
                v.push_back(a1[i]);
                i++;
            }
            else if(a2[j]<a1[i]){
                v.push_back(a2[j]);
                j++;
            }
        }
        while(i<a1.size()  and v.size()<=(k-1)){
            v.push_back(a1[i]);
            i++;
        }
        while(j<a2.size() and v.size()<=(k-1)){
            v.push_back(a2[j]);
            j++;
        }
        //for(auto e:v) cout<<e;
        if((n+m)%2==1) return v[v.size()-1];
        else{
            double ans=(v[v.size()-1]+v[v.size()-2])/2.0;
            return ans;
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
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        // Your code here
        vector<int>v2(26,0);
        int m=str.size(),f=0;
        for(int i=0;i<patt.size();i++){
            v2[patt[i]-97]++;
        }
        for(int i=0;i<str.size();i++){
            if(v2[str[i]-97]>=1) {
                m=min(m,i);
                f=1;
            }
        }
        if(f==0) return -1;
        return m;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
	return 0;
}

// } Driver Code Ends
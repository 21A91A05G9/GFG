//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/
/*You are required to complete this method*/

class Solution
{
    public:
    long long int m=1e9+7;
    int Occurences(int i,int j,string &s,string &t,string &str,vector<vector<int>>&dp){
        
        if(j==t.size() and str==t) return 1;
        if(j>=t.size() or i>=s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int p=0,np=0;
      
        if(s[i]==t[j]){ 
            str.push_back(s[i]);
            p=Occurences(i+1,j+1,s,t,str,dp);
            str.pop_back();
        }
        np=Occurences(i+1,j,s,t,str,dp);
        return dp[i][j]=(np%m+p%m)%m;
    }
    int subsequenceCount(string s, string t)
    {
      //Your code here
      string str;
      vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
      return Occurences(0,0,s,t,str,dp);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends
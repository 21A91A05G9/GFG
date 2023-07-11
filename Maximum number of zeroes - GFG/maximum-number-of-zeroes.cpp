//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
    	string MaxZero(string a[],int n)
    	{
    	    int m=0,num=0;
    	    string s="-1",t1;
    	     for(int i=0;i<n;i++){
    	         int cnt=0;
    	         for(char e : a[i]){
    	             if(e=='0') cnt++;
    	         }
    	         if(cnt>m) {
        	         s=a[i];
        	         m=max(m,cnt);
        	 
    	         }
    	         else if(cnt==m and m>0){
    	             int val=a[i].size();
    	             if(a[i].size()>s.size()){
    	                 s=a[i];
    	             }
    	             else if(a[i].size()==s.size()){
    	                 int j=0;
    	                 
    	                 while(j<s.size() and s[j]==a[i][j]){
    	                     j++;
    	                 }
    	                 int v1=(int)(s[j]),v2=(int)(a[i][j]);
    	                 if(v2>v1){
    	                     s=a[i];
    	                 }
    	             }
    	         }
    	     } 
    	     return s;
    	}
};
	 

//{ Driver Code Starts.

int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin >> n;
	    string a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    

      

        Solution ob;
        cout << ob.MaxZero(a,n) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
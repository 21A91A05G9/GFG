//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>v;
		    for(int i=1;i<pow(2,s.size());i++){
		        int n=i,k=0;
		        string t;
		        while(n){
		            if((n&1)==1){
		                t+=s[k];
		            }
		            k++;
		            n>>=1;
		        }
		        v.push_back(t);
		    }
		    sort(v.begin(),v.end());
		    return v;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends
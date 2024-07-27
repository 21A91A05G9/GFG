//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void solve(int i, string s, vector<string>&ans) {
	        if(i == s.size()) {
	            auto it = find(ans.begin(), ans.end(), s);
	            if(it == ans.end()) ans.push_back(s);
	            return;
	        }
	        
	        for(int j=i; j<s.size(); j++){
	            swap(s[i], s[j]);
	            solve(i+1, s, ans);
	            swap(s[i], s[j]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>ans;
		    solve(0, S, ans);
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
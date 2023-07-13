//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void fun(vector<int>A,int i,int N,vector<int>&v,vector<vector<int>>&ans){
        if(i==N) {
            ans.push_back(v);
            return;
        }
        v.push_back(A[i]);
        fun(A,i+1,N,v,ans);
        v.pop_back();
        fun(A,i+1,N,v,ans);
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        int N=A.size();
        vector<int>v;
        vector<vector<int>>ans;
        fun(A,0,N,v,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends
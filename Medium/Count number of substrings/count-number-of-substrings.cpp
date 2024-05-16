//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
  public:
    long long int find(string s, int k) {
        int j=0,i=0, d=0;
    	long long int cnt = 0;
    	vector<int>v(26,0);
    	for (int i = 0; i < s.size(); i++) {
            v[s[i] - 'a']++;
            if (v[s[i] - 'a'] == 1) 
                d++;
            
            while (d > k) {
                v[s[j] - 'a']--;
                if (v[s[j] - 'a'] == 0) 
                    d--;
                j++;
            }
            
            cnt += (i - j + 1);
        }
    
    	return cnt;
    }
    long long int substrCount (string s, int k) {
    	//code here.
    	return find(s,k) - find(s,k-1);
    	
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends
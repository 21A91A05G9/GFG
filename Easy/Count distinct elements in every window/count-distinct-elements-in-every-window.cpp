//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        unordered_map<int,int>mp;
        vector<int>v;
        int j=0, cnt=0;
        for(int i=0; i<n; i++) {
            if((i-j) == k) {
                mp[A[j]]--;
                if(mp[A[j]] == 0) cnt--;
                j++;
            }
            mp[A[i]]++;
            if(mp[A[i]] == 1) cnt++;
            if((i-j) == (k-1)) v.push_back(cnt);
        }

        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
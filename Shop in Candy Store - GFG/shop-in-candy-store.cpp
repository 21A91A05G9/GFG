//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code heres
        sort(candies,candies+N);
        int val=N/(K+1);
        int mi=0,ma=0;
        if(N%(K+1)!=0) val+=1;
        for(int i=0;i<val;i++){
            mi+=candies[i];
        }
        for(int i=N-1;i>=(N-val);i--){
            ma+=candies[i];
        }
        vector<int>v;
        v.push_back(mi); v.push_back(ma);
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
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends
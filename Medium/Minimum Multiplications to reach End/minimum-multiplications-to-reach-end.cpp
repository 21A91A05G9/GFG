//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<long long int,long long int>>q;
        vector<int>v(100000+1,0);
        q.push({start,0});
        v[start]=1;
        if(start==end) return 0;
        long long int cnt=0,m=100000;
        while(q.size()>0){
            long long int top=q.front().first;
            cnt=q.front().second;
            for(long long int i=0;i<arr.size();i++){
                
                long long int  val=(top%m*arr[i]%m)%m;
                
                if(v[val]==0){
                    
                    if(val==end){
                        return cnt+1;
                    }
                 
                    q.push({val,cnt+1});
                    v[val]=1;
                    
                }
                
            }
            
            q.pop();

        }
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
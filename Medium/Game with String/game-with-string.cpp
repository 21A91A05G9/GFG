//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minValue(string s, int k){
        // code here
        int sum=0;
        map<char,int>mp;
        vector<int>v;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto e:mp){
            v.push_back(e.second);
        }
        sort(v.rbegin(),v.rend());
        // for(auto e:v) cout<<e<<" ";
        
        while(k>0){
            v[0]--;
            k--;
            
            for(int i=1;i<v.size();i++){
                if(k==0) break;
                if(v[i]>v[i-1]) { v[i]--; k--; }
                else break;
            }
        }
        for(auto e:v) sum+=(e*e);
        return sum;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
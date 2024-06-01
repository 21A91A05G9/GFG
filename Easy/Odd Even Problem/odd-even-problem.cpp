//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code herem
        unordered_map<char,int>mp;
        int e=0, o=0;
        for(int i=0; i<s.size(); i++) {
            mp[s[i]]++;
        }
        
        for(auto ele:mp) {
            int val = ele.first;
            if(ele.second%2==0 and (val)%2==0) e++;
            if(ele.second%2==1 and (val)%2==1) o++;
            
        }
        
        e+=o;
        if(e%2==0) return "EVEN";
        else return "ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        int flag = 0, j = 0;
        string t;
        
        while(j<s.size() and s[j]=='0') j++;
        for(int i=j; i<s.size(); i++) t += s[i];
       
        
        for(int i=t.size()-1; i>=0; i--) {
            if(t[i] == '0') {
                t[i] = '1';
                flag = 1;
                break;
            } else t[i] = '0';
          
        }
        
        
        if(flag == 1) {
            return t;
        }
        else {
            t = '1' + t;
            return t;
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
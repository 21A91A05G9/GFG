//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    void solve(int i, string s, vector<string>&ans, int len, string t) {
        if(i == s.size() && len == 4) {
            t.pop_back();
            ans.push_back(t);
            return;
        }
        if(i >= s.size() or len > 4) return;
        
        string str;
        for(int j=i; j<s.size(); j++) {
            str += s[j];
            
            int val = stoi(str);
            string st = to_string(val);
            
            if(st.size() == str.size() and val >= 0 and val<= 255) {
                solve(j+1, s, ans, len+1, t+str+'.');
            }
            else return;
        }
        return;
    }
    vector<string> genIp(string &s) {
        // Your code here
        vector<string>ans;
        string str;
        solve(0, s, ans, 0, str);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends
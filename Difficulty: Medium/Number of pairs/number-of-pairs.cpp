//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
        sort(arr.begin(), arr.end());
       
        long long two = 0, three = 0, one = 0, cnt=0;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] > 3) break;
            if(arr[i] == 1) one++;
            if(arr[i] == 2) two++;
            if(arr[i] == 3) three++;
        }
        for(int i=0; i<brr.size(); i++) {
            // cout<<cnt<<" ";
            if(brr[i] == 1)  { cnt += (arr.size()-one); continue; }
            else if(brr[i] == 2 || brr[i] == 4) { cnt += three; continue; }
            else if(brr[i] == 3) continue;
            else {
                auto it = lower_bound(arr.begin(), arr.end(), brr[i]) - arr.begin();
                cnt += (it-one);
            }
            
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends
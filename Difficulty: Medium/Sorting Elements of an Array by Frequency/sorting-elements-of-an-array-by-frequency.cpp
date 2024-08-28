//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    static bool comp(pair<int, int>&a, pair<int, int>&b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int, int>mp;
        for(auto e: arr) mp[e]++;
        
        vector<pair<int, int>>vp;
        
        for(auto e: mp)  vp.push_back({e.second, e.first});
        
        sort(vp.begin(), vp.end(), comp);
      
        int i=0;
        for(int j=0; j<vp.size(); j++){
            int val = vp[j].second;
            int k = vp[j].first;
            while(k--) arr[i++] = val;
        }
        
        return arr;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
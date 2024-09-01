//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        int sum = 0, sumA=0, sumB=0, i=0, j=0, val = -1;
        
        while(i < arr1.size() && j < arr2.size()) {
            while(i < arr1.size() && arr1[i] < arr2[j]) {
                sumA += arr1[i++];
            }
            while(j < arr2.size() && arr2[j] < arr1[i]) {
                sumB += arr2[j++];
            }
            
            if(arr1[i] == arr2[j]) {
                sum += max(sumA, sumB);
                val = arr1[i];
                sum += val;
                sumA = 0;
                sumB = 0;
            }
            
            while(i < arr1.size() && arr1[i] == val) i++;
            while(j < arr2.size() && arr2[j] == val) j++;
        }

        while(i < arr1.size()) sumA += arr1[i++];
        while(j < arr2.size()) sumB += arr2[j++];
        
        sum += max(sumA, sumB);
        
        return sum;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
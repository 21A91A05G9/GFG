//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        map<char,int>m1,m2;
        for(auto e:a){
            m1[e]++;
        }
        for(auto e:b){
            m2[e]++;
        }
        if(m1.size()!=m2.size()) return 0;
        else{
            for(auto e:m1){
                if(m1[e.first]!=m2[e.first]) return 0;
            }
        }
        return 1;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends
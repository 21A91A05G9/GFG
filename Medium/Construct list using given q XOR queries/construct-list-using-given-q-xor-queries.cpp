//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        // code here
        vector<int>v;
        v.push_back(0);
        vector<pair<int,pair<int,int>>>x;
        int ind1=0;
        
        for(int i=0; i<queries.size(); i++) {
            if(queries[i][0] == 0) v.push_back(queries[i][1]);
            else {
                x.push_back({queries[i][1],{ind1,v.size()}});
                ind1 = v.size();
            }
        }
        
        int xx = 0;
        for(int i=x.size()-1; i>=0; i--) {
            // cout<<e.first<<" "<<e.second.first<<" "<<e.second.second<<"\n";
            int i1 = x[i].second.first, i2 = x[i].second.second; 
            xx ^= x[i].first;
            
            while(i1<i2) {
                v[i1++] ^= xx;
            }
        }
        
        sort(v.begin(),v.end());
        return v;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int q;
        scanf("%d", &q);

        vector<vector<int>> queries(q, vector<int>(2));
        Matrix::input(queries, q, 2);

        Solution obj;
        vector<int> res = obj.constructList(q, queries);

        Array::print(res);
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    void solve(int node, vector<vector<int>>&adj, vector<int>&ch, stack<int>&st) {
        if(ch[node] == 1) return;
        ch[node] = 1;
        for(auto e: adj[node]) {
            solve(e, adj, ch, st);
        }
        st.push(node);
    }
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        //code here
        stack<int>st;
        vector<int>ch(n, 0);
        vector<vector<int>>adj(n);
        
        for(auto e: pre) {
            adj[e[0]].push_back(e[1]);
        }
        
        for(int i=0; i<n; i++) {
            if(ch[i] == 0) solve(i, adj, ch, st);
        }
        
        vector<int>r(n, 0), v;
        int rank=0;
        
        while(st.size() > 0) {
            r[st.top()] = rank++;
            // cout<<st.top();
            v.push_back(st.top());
            st.pop();
        }
        
        for(int i=0; i<n; i++) {
            for(auto e: adj[i]) {
                if(r[e] <= r[i]) return {};
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
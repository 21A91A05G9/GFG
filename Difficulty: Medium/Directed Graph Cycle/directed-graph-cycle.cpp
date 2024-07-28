//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    void solve(int node, vector<int>adj[], vector<int>&ch, stack<int>&st) {
        if(ch[node] == 1) return;
        ch[node] = 1;
        for(auto e: adj[node]) {
            solve(e, adj, ch, st);
        }
        st.push(node);
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        stack<int>st;
        vector<int>ch(V, 0);
        for(int i=0; i<V; i++){
            if(ch[i] == 0) {
                solve(i, adj, ch, st);
            }
        }
        
        vector<int>r(V, 0);
        int rank = 0;
        while(st.size() > 0) {
            r[st.top()] = rank++;
            st.pop();
        }
        
        for(int i=0; i<V; i++) {
            for(auto e: adj[i]) {
                if(r[i] > r[e]) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
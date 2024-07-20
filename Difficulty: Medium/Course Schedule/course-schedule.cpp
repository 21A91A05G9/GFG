//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    void topoSort(int i, vector<int>&ch, vector<int>adj[], stack<int>&st) {
      
        for(auto e: adj[i]) {
            if(ch[e] == 0) {
                ch[e] = 1;
                topoSort(e, ch, adj, st);
            }
        }
        
        st.push(i);
        
    }
    
    vector<int> findOrder(int n, int m, vector<vector<int>> p) 
    {
        //code here
        vector<int>adj[n];
        for(int i=0; i<m; i++) {
            adj[p[i][0]].push_back(p[i][1]);
        }
        
        
        vector<int>ch(n, 0);
        stack<int>st;
        
        for(int i=0; i<n; i++) {
            if(ch[i] == 0) {
                ch[i] = 1;
                topoSort(i, ch, adj, st);
            }
        }
        
        vector<int>v, rank(n,0);
        int r=1;
        while(st.size() > 0) {
            v.push_back(st.top());
            rank[st.top()] = r++;
            st.pop();
        }
        
        for(int i=0; i<n; i++) {
            for(auto e: adj[i]) {
                if(rank[i] >= rank[e]) return {};
            }
        }
        reverse(v.begin(), v.end());
        // for(auto e: v)  cout<<e<<" ";
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
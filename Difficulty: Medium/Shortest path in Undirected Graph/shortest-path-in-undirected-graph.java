//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int m=sc.nextInt();
            int[][] edge = new int[m][2];
            for(int i=0;i<m;i++){
                edge[i][0]=sc.nextInt();
                edge[i][1]=sc.nextInt();
            }
            int src=sc.nextInt();
            Solution obj = new Solution();
            int res[] = obj.shortestPath(edge,n,m,src);
            for(int i=0;i<n;i++){
                System.out.print(res[i]+" ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


class Solution {
    
    public int[] shortestPath(int[][] edges,int n,int m ,int src) {
        // Code here
        
        HashMap<Integer, ArrayList> adj = new HashMap<>();
        
        for(int i=0; i<edges.length; i++) {
            int u = edges[i][0], v = edges[i][1];
            adj.putIfAbsent(u, new ArrayList<>());
            adj.putIfAbsent(v, new ArrayList<>());
            
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        int[] ans = new int[n];
        
        Arrays.fill(ans, Integer.MAX_VALUE);
        
        Queue<Map.Entry<Integer, Integer>> q = new LinkedList<>();
        q.add(new AbstractMap.SimpleEntry<>(src, 0));
        
        while(q.size() > 0) {
            int size = q.size();
            
            for(int i=0; i<size; i++) {
                Map.Entry<Integer, Integer> front = q.poll();
                int dis = front.getValue();
                int node = front.getKey();
                
                ans[node] = Math.min(ans[node], dis);
                
                List<Integer> neighbors = adj.get(node);
                if (neighbors != null) { 
                    for (Integer neighbor : neighbors) {
                        if(dis+1 < ans[neighbor]) q.add(new AbstractMap.SimpleEntry<>(neighbor, dis + 1));
                    }
                }

            }
        }
        
        for(int i=0; i<n; i++) {
            if(ans[i] == Integer.MAX_VALUE) ans[i] = -1;
        }
        return ans;
    }
}
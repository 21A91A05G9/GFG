//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int[] a = new int[s.length];
            for (int i = 0; i < s.length; i++) a[i] = Integer.parseInt(s[i]);

            Solution obj = new Solution();
            int res = obj.pairWithMaxSum(a);
            System.out.println(res);
        }
    }
}

// } Driver Code Ends



class Solution {
    public int pairWithMaxSum(int[] arr) {
        // code here
        int n = arr.length;
        if(n <= 1) return -1;
        if(n == 2) return arr[0]+arr[1];
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int maxi = 0, j=0;
        for(int i=0; i<n; i++) {
            pq.add(arr[i]);
            
            if(pq.size() >= 2) {
                int x = pq.peek();
                int r = pq.poll();
                int y = pq.peek();
                pq.add(r);
                
                if(x+y > maxi) maxi = x+y;
                else {
                    while(pq.size() > 1 && (x+y) <= maxi) {
                        int a = pq.peek();
                        int rr = pq.poll();
                        int b = pq.peek();
                        pq.add(rr);
                        
                        if(a+b > maxi) maxi = a+b;
                        
                        pq.remove(arr[j]);
                        j++;
                    }
                }
            }
            // System.out.println(i + " " + maxi);
        }
        return maxi;
    }
}

//9 2 3 2 5 2 8

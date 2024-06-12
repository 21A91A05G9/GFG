//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            int n;
            n = Integer.parseInt(br.readLine());

            Solution obj = new Solution();
            int res = obj.countNumberswith4(n);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends



class Solution {
    public static int findFour(int n) {
        while(n > 0) {
            if(n%10 == 4) return 1;
            n /= 10;
        }
        return 0;
    }
    public static int countNumberswith4(int n) {
        // code here
        int cnt = 0;
        
        for(int i=4; i<=n; i++) {
            cnt += findFour(i);
        }
        
        return cnt;
    }
}

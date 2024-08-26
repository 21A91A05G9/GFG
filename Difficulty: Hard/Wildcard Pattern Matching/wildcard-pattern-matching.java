//{ Driver Code Starts
import java.util.*;

class WildcardPattern {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t > 0) {
            String pat = sc.nextLine();
            String text = sc.nextLine();
            Solution g = new Solution();
            System.out.println(g.wildCard(pat, text));
            t--;
        }
    }
}
// } Driver Code Ends


class Solution {
    public int solve(int i, int j, String pattern, String str, int dp[][]) {
        if(j < 0 && i < 0) return 1;
        if(j < 0) return 0;
        if(i < 0) {
            while(j >= 0 && pattern.charAt(j) == '*') j--;
            if(j < 0) return 1;
            else return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        if(pattern.charAt(j) == str.charAt(i) || (pattern.charAt(j) == '?')) return solve(i-1, j-1, pattern, str, dp);
        else {
            if(pattern.charAt(j) == '*')  return dp[i][j] = ((solve(i-1, j, pattern, str, dp) != 0) || (solve(i, j-1, pattern, str, dp) != 0)) ? 1 : 0;
            else return dp[i][j] = 0;
        }
        
    }
    public int wildCard(String pattern, String str) {
        // Your code goes here
        int m = pattern.length(), n = str.length();
        int[][] dp = new int[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) Arrays.fill(dp[i], -1);
        }
        return solve(n-1, m-1, pattern, str, dp);
    }
}

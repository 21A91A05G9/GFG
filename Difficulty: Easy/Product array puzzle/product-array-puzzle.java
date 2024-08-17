//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int n = sc.nextInt();
            int[] array = new int[n];
            for (int i = 0; i < n; i++) {
                array[i] = sc.nextInt();
            }
            Solution ob = new Solution();
            long[] ans = new long[n];
            ans = ob.productExceptSelf(array);

            for (int i = 0; i < n; i++) {
                System.out.print(ans[i] + " ");
            }
            System.out.println();
            t--;
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public static long[] productExceptSelf(int nums[]) {
        // code here
        
        int n = nums.length;
        long[] prod = new long[n];
        long[] ans = new long[n];
        ans[0] = 1;
        
        prod[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            prod[i] = nums[i]*prod[i+1];
        }
        
        
        long p = nums[0];
        for(int i=1; i<n-1; i++) {
            ans[i] = p*prod[i+1];
            p *= nums[i];
        }
        
        if(n > 1) {
            ans[0] = prod[1];
            ans[n-1] = p;
        }
        return ans;
    }
}

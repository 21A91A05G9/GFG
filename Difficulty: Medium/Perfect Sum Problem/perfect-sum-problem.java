//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    int sum = sc.nextInt();
                    int arr[] = new int[n];
                    for(int i = 0;i<n;i++)
                    arr[i] = sc.nextInt();
                    
                    Solution ob = new Solution();
                    System.out.println(ob.perfectSum(arr,n,sum));
                }
        }
}    
// } Driver Code Ends


class Solution{
    int solve(int i, int arr[], int n, int sum, int dp[][]) {
       
        
        if(i >= n || sum < 0) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        int p = 0, np = 0, m = (int)1e9+7;
        
        if((sum-arr[i]) == 0) p = (1 + solve(i+1, arr, n, sum-arr[i], dp)%m ) %m;
        else p = solve(i+1, arr, n, sum-arr[i], dp);
        
        np = solve(i+1, arr, n, sum, dp);
        
        return dp[i][sum] = (p%m+np%m)%m;
    }
	public int perfectSum(int arr[],int n, int sum) 
	{ 
	    // Your code goes here
	    int[][] dp = new int[n][sum+1];
	    for(int i=0; i<n; i++){
	        Arrays.fill(dp[i], -1);
	    }
	    return solve(0, arr, n, sum, dp);
	    
	} 
}
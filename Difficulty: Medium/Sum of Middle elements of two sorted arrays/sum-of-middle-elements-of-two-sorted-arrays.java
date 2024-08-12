//{ Driver Code Starts
// Initial Template for Java

import java.util.*;


// } Driver Code Ends
// User function Template for Java

class Solution {
    public int SumofMiddleElements(int[] arr1, int[] arr2) {
        // code here
        int n = arr1.length, m=arr2.length;
        
        int k = (n+m)/2+1, val1=0, val2=0, i=0, j=0;
        
        if((n+m)%2 == 1) k++;
        
        
        while(i < n && j < m && k>0) {
            if(arr1[i] <= arr2[j]) {
                val1 = val2;
                val2 = arr1[i];
                i++;
                k--;
            }
            else{
                val1 = val2;
                val2 = arr2[j];
                j++;
                k--;
            }
           
        }
        
        while(i < n && k>0) {
            val1 = val2;
            val2 = arr1[i];
            i++;
            k--;
        }
        
        while(j < m && k>0) {
            val1 = val2;
            val2 = arr2[j];
            j++;
            k--;
        }
        
        
        return (val1+val2);
        
    }
}

//{ Driver Code Starts.
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // Consume newline
        while (t-- > 0) {
            String[] input1 = sc.nextLine().split(" ");
            int[] arr = new int[input1.length];
            for (int i = 0; i < input1.length; i++) {
                arr[i] = Integer.parseInt(input1[i]);
            }

            String[] input2 = sc.nextLine().split(" ");
            int[] brr = new int[input2.length];
            for (int i = 0; i < input2.length; i++) {
                brr[i] = Integer.parseInt(input2[i]);
            }

            Solution ob = new Solution();
            int res = ob.SumofMiddleElements(arr, brr);
            System.out.println(res);
        }
    }
}

// } Driver Code Ends
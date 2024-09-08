//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String line = br.readLine();
            String[] tokens = line.split(" ");

            // Create an ArrayList to store the integers
            ArrayList<Integer> array = new ArrayList<>();

            // Parse the tokens into integers and add to the array
            for (String token : tokens) {
                array.add(Integer.parseInt(token));
            }

            int[] arr = new int[array.size()];
            int idx = 0;
            for (int i : array) arr[idx++] = i;

            System.out.println(new Solution().minJumps(arr));
            // System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {
    static int minJumps(int[] arr) {
        // your code here
        int step = arr[0], cnt = 1, maxi = step;
        
        if(arr.length == 1) return 0;
        if(arr[0] == 0) return -1;
        if(arr[0] >= arr.length-1) return 1;
        
        for(int i=1; i<arr.length; i++) {
            step--;
            
            maxi = Math.max(maxi, i+arr[i]);
            if(maxi >= (arr.length-1)) return cnt+1;
            
            if(step == 0) {
                step = maxi-i;
                cnt++;
                if(step <= 0) return -1;
            }
        }
        return -1;
    }
}
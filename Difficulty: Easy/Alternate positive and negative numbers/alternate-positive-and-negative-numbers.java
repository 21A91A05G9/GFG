//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String input = br.readLine();
            String[] inputArray = input.split("\\s+");
            ArrayList<Integer> arr = new ArrayList<>();

            for (String s : inputArray) {
                arr.add(Integer.parseInt(s));
            }

            new Solution().rearrange(arr);
            for (int num : arr) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    void rearrange(ArrayList<Integer> arr) {
        // code here
        ArrayList<Integer> pos = new ArrayList<>();
        ArrayList<Integer> neg = new ArrayList<>();
        
        for(Integer ele : arr) {
            if(ele < 0) neg.add(ele);
            else pos.add(ele);
        }
        
        int i=0, j=0, k=0;
        
        while(i<pos.size() && j<neg.size()) {
            arr.set(k++, pos.get(i++));
            arr.set(k++, neg.get(j++));
        }
        
        while(i<pos.size())  arr.set(k++, pos.get(i++));
        while(j<neg.size())  arr.set(k++, neg.get(j++));
    }
}
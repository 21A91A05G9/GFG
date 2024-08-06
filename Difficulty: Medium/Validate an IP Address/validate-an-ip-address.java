//{ Driver Code Starts
// Initial Template for Java

// Initial Template for Java

import java.io.*;
import java.util.*;

public class validip {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            String s = sc.next();
            Solution obj = new Solution();

            if (obj.isValid(s))
                System.out.println("true");
            else
                System.out.println("false");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {

    public boolean isValid(String str) {
        // Write your code here
        int cnt = 0;
        String s = "";
        for(int i=0; i<str.length(); i++) {
            if(i == str.length()-1) s += str.charAt(i);
            if(str.charAt(i) == '.' || i == str.length()-1) {
                if(s.length() == 0) return false;
                int val = Integer.valueOf(s);
                String t = String.valueOf(val);
                if(t.length() != s.length() || val < 0 || val > 255) return false;
                cnt++; s="";
               
            }
            else s += str.charAt(i);
            
        }
        //  System.out.println(cnt);
        if(cnt == 4) return true;
        return false;
        
    }
}
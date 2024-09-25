//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
		
		while(test > 0){
		    String s = scan.next();
		    String t = scan.next();
		    
		    System.out.println(new Solution().smallestWindow(s, t));
		    test--;
		}
	}
}
// } Driver Code Ends


class Solution
{
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    public static String smallestWindow(String s, String p)
    {
        // Your code here
        int[] freq = new int[255];
        int[] ch = new int[255];
        // Deque<Character> dp = new Deque<>();
        
        String ans = "-1";
        int j = 0, cnt = p.length(), start = 0, mini = Integer.MAX_VALUE;
        
        for(int i=0; i<p.length(); i++) {
            ch[p.charAt(i)]++;
        }
        
        for(int i=0; i<s.length(); i++) {
            
            
            freq[s.charAt(i)]++;
            
            if(ch[s.charAt(i)] > 0 && ch[s.charAt(i)] >= freq[s.charAt(i)]) cnt --;
          
            while(cnt == 0){
                
                if((i-j+1) < mini) {
                    mini = i-j+1;
                    start = j;
                }
               
                freq[s.charAt(j)]--;
                
                if(ch[s.charAt(j)] > 0 && ch[s.charAt(j)] > freq[s.charAt(j)]) cnt++;
                j++;
                
            }
            
            // System.out.print("cnt:"+cnt+" ");
        }
        
        if(mini != Integer.MAX_VALUE) {
            ans = s.substring(start, start+mini);
            return ans;
        }
        return ans;
    }
}
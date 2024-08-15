//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class GfG {
    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data);
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String str[] = read.readLine().trim().split(" ");
            int n = str.length;
            Node head = new Node(Integer.parseInt(str[0]));
            Node tail = head;
            for (int i = 1; i < n; i++) {
                tail.next = new Node(Integer.parseInt(str[i]));
                tail = tail.next;
            }
            Solution obj = new Solution();
            head = obj.addOne(head);
            printList(head);
        }
    }
}
// } Driver Code Ends


/*
class Node{
    int data;
    Node next;

    Node(int x){
        data = x;
        next = null;
    }
}
*/

class Solution {
    Node reverse(Node head) {
        Node prev = null;
        
        Node temp = head;
        
        while(temp != null) {
            Node curr = temp.next;
            temp.next = prev;
            prev = temp;
            temp = curr;
        }
        
        return prev;
    }
    
    public Node addOne(Node head) {
        // code here.
        head = reverse(head);
        
        Node temp = head, prev = head;
        int carry = 1;
        
        while(temp != null) {
            int val = temp.data+carry;
            temp.data = val%10;
            carry = val/10;
            prev = temp;
            temp = temp.next;
            
            if(carry == 0) break;
        }
        
        if(carry == 1) {
            
            Node nn = new Node(1);
            prev.next=nn;
        }
        
        head = reverse(head);
        
        return head;
    }
}

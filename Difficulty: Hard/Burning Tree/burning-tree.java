//{ Driver Code Starts
//Initial Template for Java


import java.util.LinkedList;
import java.util.Queue;
import java.io.*;
import java.util.*;

class Node {
	int data;
	Node left;
	Node right;

	Node(int data) {
		this.data = data;
		left = null;
		right = null;
	}
}

class GfG {

	static Node buildTree(String str) {

		if (str.length() == 0 || str.charAt(0) == 'N') {
			return null;
		}

		String ip[] = str.split(" ");
		// Create the root of the tree
		Node root = new Node(Integer.parseInt(ip[0]));
		// Push the root to the queue

		Queue<Node> queue = new LinkedList<>();

		queue.add(root);
		// Starting from the second element

		int i = 1;
		while (queue.size() > 0 && i < ip.length) {

			// Get and remove the front of the queue
			Node currNode = queue.peek();
			queue.remove();

			// Get the current node's value from the string
			String currVal = ip[i];

			// If the left child is not null
			if (!currVal.equals("N")) {

				// Create the left child for the current node
				currNode.left = new Node(Integer.parseInt(currVal));
				// Push it to the queue
				queue.add(currNode.left);
			}

			// For the right child
			i++;
			if (i >= ip.length)
				break;

			currVal = ip[i];

			// If the right child is not null
			if (!currVal.equals("N")) {

				// Create the right child for the current node
				currNode.right = new Node(Integer.parseInt(currVal));

				// Push it to the queue
				queue.add(currNode.right);
			}
			i++;
		}

		return root;
	}

	static void printInorder(Node root) {
		if (root == null)
			return;

		printInorder(root.left);
		System.out.print(root.data + " ");

		printInorder(root.right);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int t = Integer.parseInt(br.readLine());

		while (t > 0) {
			String s = br.readLine();
			int target = Integer.parseInt(br.readLine());
			Node root = buildTree(s);

			Solution g = new Solution();
			System.out.println(g.minTime(root, target));
			t--;

		}
	}
}



// } Driver Code Ends


//User function Template for Java

class Solution
{
    /*class Node {
    	int data;
    	Node left;
    	Node right;
    
    	Node(int data) {
    		this.data = data;
    		left = null;
    		right = null;
    	}
    }*/
    public void findParent(Node root, HashMap<Integer, Node> mp) {
        if(root == null) return;
        
        if(root.left != null) {
            mp.put(root.left.data, root); 
            findParent(root.left, mp);
        }
        if(root.right != null) {
            mp.put(root.right.data, root); 
            findParent(root.right, mp);
        }
    }
    
    public Node findNode(Node root, int target) {
        if(root == null) return null;
        
        if(root.data == target) return root;
        
        Node l = findNode(root.left, target);
        Node r = findNode(root.right, target);
        
        if(l != null) return l;
        else return r;
        
    } 
    
    public int burnTime(Node root, HashMap<Integer, Node> mp) {
        if(root == null) return 0;
        int cnt = 0;
        
        HashMap<Node, Integer> ch = new HashMap<>();
        Queue<Node> q = new LinkedList<>();
        
        q.add(root);
        ch.put(root, 1);
       
        while(q.size() > 0) {
            
            int n = q.size(), f = 0;
    
            for(int i=0; i<n; i++) {
                Node node = q.peek();
                q.poll();
                
                
                if(node.left != null && !ch.containsKey(node.left)) {
                    q.add(node.left);
                    ch.put(node.left, 1);
                    f=1;
                }
                if(node.right != null && !ch.containsKey(node.right)) {
                    q.add(node.right);
                    ch.put(node.right, 1);
                    f=1;
                }
                if(mp.containsKey(node.data) && !ch.containsKey(mp.get(node.data))) {
                    q.add(mp.get(node.data));
                    ch.put(mp.get(node.data), 1);
                    f=1;
                }
            }
            if(f == 1) cnt++;
        }
        return cnt;
    }
    
    public  int minTime(Node root, int target) 
    {
        // Your code goes here
        if(root == null) return 0;
        
        HashMap<Integer, Node> mp = new HashMap<>();
        
        findParent(root, mp);
        Node node = findNode(root, target);
        return burnTime(node, mp);
        
    }
}
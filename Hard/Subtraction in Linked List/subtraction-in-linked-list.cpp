//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    long long int num(Node*head){
        long long int val=0;
        while(head){
            val+=1;
            head=head->next;
        }
        return val;
    }
    Node* remove(Node *head){
        
        while(head and head->data==0){
            head=head->next;
        }
        if(head==NULL)  {
            Node *res=new Node(0);
            return res;
        }
        return head;
    }
    
    Node* reverse(Node *head){
        Node *prev=NULL,*temp=head;
        while(temp){
            Node *cur=temp->next;
            temp->next=prev;
            prev=temp;
            temp=cur;
        }
        return prev;
        
    }
    
    Node* sub(Node *head1,Node* head2){
        long long int carry=0,a,b,res=0;
       
        Node *temp1=head1,*temp2=head2, *temp=new Node(0),*ans=temp;
        while(temp1 and temp2){
            a=temp1->data;
            b=temp2->data;
            
            a+=carry;
            
            if(a<b){
                a=(a+10);
                carry=-1;
            }
            else{
                carry=0;
            }
            
            long long int c=(a-b);
            res=res*10+c;
            Node *t=new Node(c);
            temp->next=t;
            temp=temp->next;
            
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        while(temp1){
            a=temp1->data;
            
            if(carry==-1 and a==0){
                a=a+10+carry;
                carry=-1;
            }
            else if(carry==-1){
                a-=1;
                carry=0;
            }
            
            res=res*10+a;
            Node *t=new Node(a);
            temp->next=t;
            temp=temp->next;
            
            
            temp1=temp1->next;
            
        }
        return ans->next;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
       
        
        // cout<<abs(val1-val2)<<"\n";
        head1=remove(head1);
        head2=remove(head2);
        // return head2;
        Node* ans=new Node(0);
        if(head1->data==0 and head1->next==NULL and head2->data==0 and head2->next==NULL) return ans;
        // cout<<"a";
        if(head1->data==0 and head1->next==NULL) return head2;
        // cout<<"b";
        if(head2->data==0 and head2->next==NULL) return head1;
        // cout<<"c";
        long long int val1=num(head1);
        long long int val2=num(head2);
        // return head1;
       
        
        if(val1>val2)  ans= reverse(sub(reverse(head1),reverse(head2)));
        else if(val1==val2) {
            Node *t1=head1,*t2=head2;
            
            while(t1!=NULL and t1->data==t2->data){
                t1=t1->next;
                t2=t2->next;
            }
            if(t1==NULL) return ans;
            else if(t1->data > t2->data ) ans=reverse(sub(reverse(head1),reverse(head2)));
            else ans=reverse(sub(reverse(head2),reverse(head1)));
        }
        
        else ans= reverse(sub(reverse(head2),reverse(head1)));
        
        
        return remove(ans);
        
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends
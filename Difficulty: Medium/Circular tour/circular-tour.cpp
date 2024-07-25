//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       vector<int>petrol, distance;
       
       for(int i=0; i<n; i++) {
           petrol.push_back(p[i].petrol);
           distance.push_back(p[i].distance);
           
       }
        for(int i=0; i<n; i++) {
           petrol.push_back(p[i].petrol);
           distance.push_back(p[i].distance);
           
       }
       
       int sum = 0, start = 0;
       for(int i=0; i<petrol.size(); i++) {
           if(start > n) return -1;
           if((i-start) == n) return start;
           sum += petrol[i];
           if(sum >= distance[i]) {
               sum -= distance[i];
           }
           else{
               start = i+1;
               sum =0;
           }
       }
       return -1;
       
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void words(vector<string>a,int N,int i,string s,vector<string>&ans)
    {
        if(i==N) {
            ans.push_back(s);
            return ;
        }
        for(int j=0;j<a[i].size();j++){
            
            words(a,N,i+1,s+a[i][j],ans);
        }
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        
        string s;
        vector<string>ans;
        vector<string>com{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>arr;
        for(int i=0;i<N;i++){
            arr.push_back(com[a[i]]);
        }
        //for(auto e:arr) cout<<e<<" ";
        words(arr,N,0,s,ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string t;
		    vector<int>v(26,0);
		    deque<char>dq;
		    for(int i=0;i<A.size();i++){
		        int ind=A[i]-97,f=0;
		        v[ind]++;
		        if(v[ind]==1){
		            dq.push_back(A[i]);
		        }
		        
		        for(auto e:dq){
		            int i=e-97;
		            if(v[i]==1){
		                f=1;
		                t+=e;
		                break;
		            }
		            dq.pop_front();
		        }
		        if(f==0) t+='#';
		    }
		    return t;
		}
		  

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
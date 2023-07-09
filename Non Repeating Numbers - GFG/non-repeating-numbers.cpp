//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int x=0;
        for(int i=0;i<nums.size();i++){
            x^=nums[i];
        }
        
        int p=0;
        while((x&1)!=1){
            x>>=1;
            p++;
        }
        
        int x1=0,x2=0;
        for(int i=0;i<nums.size();i++){
            if(((nums[i]>>p)&1)==1) x1^=nums[i];
            else x2^=nums[i];
        }
        vector<int>v;
        if(x1<=x2) { v.push_back(x1); v.push_back(x2);}
        else { v.push_back(x2); v.push_back(x1);}
        return v;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
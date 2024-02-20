//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    void wordPartition(int i,int n,string &s,vector<string>&dic,vector<string>&v,int &flag){
        if(i>=n){
            flag=1; 
            return ;
        }
        string t;
        for(int j=i;j<n;j++){
            t+=s[j];
            v.push_back(t);
            auto it=find(dic.begin(),dic.end(),t);
            if(it==dic.end())   continue;
            wordPartition(j+1,n,s,dic,v,flag);
            v.pop_back();
        }
    }
    int wordBreak(int n, string s, vector<string> &dic) {
        //code here
        vector<string>v;
        int flag=0;
        wordPartition(0,s.size(),s,dic,v,flag);
        if(flag) return 1;
        else return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends
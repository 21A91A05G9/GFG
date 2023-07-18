//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector<string>  spaceString(char str[]);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        char str[10000];
        cin>>str;
        vector<string> vec = spaceString(str);
        for(string s: vec){
            cout<<s<<"$";
        }
        cout<<endl;
    }

}

// } Driver Code Ends


/*You have to complete this function*/

void fun(char str[],int i,int N,string s,vector<string>&v){
    if(i==N) {
        v.push_back(s);
        return;
    }
    fun(str,i+1,N,s+str[i],v);
    if(i!=(N-1)) fun(str,i+1,N,s+str[i]+" ",v);
}
vector<string>  spaceString(char str[])
{
//Your code here
    vector<string>v;
    string s;
    int N=strlen(str);
    fun(str,0,N,s,v);
    return v;

}
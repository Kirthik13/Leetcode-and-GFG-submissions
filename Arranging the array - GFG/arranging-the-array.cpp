// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
      
        Rearrange( arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} // } Driver Code Ends




void Rearrange(int v[], int n)
{
    if(n==1)
    {
        return;
    }
    vector<int>v2;
    
    for(int i=0;i<n;i++)
    {
        if(v[i]<0)
        {
            v2.push_back(v[i]);
        }
    }
     for(int i=0;i<n;i++)
    {
        if(v[i]>=0)
        {
            v2.push_back(v[i]);
        }
    }
    // int j=0;
    for(int i=0;i<v2.size();i++)
    {
        v[i]=v2[i];
    }
    // Your code goes here
}
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int cc( int v[],int i,int r, vector<vector<int>>&dp)
    // {
    //     if(i==r)
    //     {
    //         return 0;
    //     }
    //     if(dp[i][r]!=-1)
    //     {
    //         return dp[i][r];
    //     }
    //   int res=INT_MAX;
    //     for(int k=i;k<r;k++)
    //     {
    //      int tot=cc(v,i,k,dp)+cc(v,k+1,r,dp)+v[i-1]*v[r]*v[k];
           
    //         res=min(tot,res);
           
    //     }
    //     return dp[i][r]=res;
    // }
    
    int fn(int v[],int idx,int j,vector<vector<int>>&dp)
    {
        if(idx>=j) return 0;
        
        if(dp[idx][j]!=-1) return dp[idx][j];
        
        int ans=INT_MAX;
        for(int k=idx;k<j;k++)
        {
            int call1=fn(v,idx,k,dp)+fn(v,k+1,j,dp)+(v[idx-1]*v[k]*v[j]);
            ans=min(call1,ans);
        }
        return dp[idx][j]=ans;
    }
    int matrixMultiplication(int n, int v[])
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // return cc(v,1,n-1,dp);
        for(int idx=n-1;idx>=1;idx--)
        {
            for(int j=idx+1;j<n;j++)
            {
                    int ans=INT_MAX;
                    for(int k=idx;k<j;k++)
                    {
                        int call1=dp[idx][k]+dp[k+1][j]+(v[idx-1]*v[k]*v[j]);
                        ans=min(call1,ans);
                    }
                    dp[idx][j]=ans;
            }
        }
        
        return dp[1][n-1];
        // return fn(v,1,n-1,dp);
        // code here
    }
    
    
//     int dp[100][100];
// int func(int arr[] ,int i, int j)
// {
//     if( i == j) return dp[i][j] = 0;

//     if(dp[i][j]!= -1) return dp[i][j];

    
//     int ans = INT_MAX;

//     for(int k = i;k < j;k++)
// {
//         int temp = func(arr,i,k) +func(arr,k+1,j) +arr[i-1] *arr[k] *arr[j];

//         ans = min(ans,temp);
//     }
//     dp[i][j]= ans;

//     return ans;
// }



//     int matrixMultiplication(int N, int arr[])

//     {
//         memset(dp,-1,sizeof(dp));

//         return func(arr,1,N-1);
//     }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    map<pair<int,int>,int>dp;
    int fn(int w, int wt[], int val[], int n,int i)
    {
        if(w<0)
        {
            return INT_MIN;
        }
        
        if(i>=n)
        {
            return 0;
        }
        if(dp.find({w,i})!=dp.end()) return dp[{w,i}];
        
        int pic=val[i]+fn(w-wt[i],wt,val,n,i+1);
        int n_pic=fn(w,wt,val,n,i+1);
        return dp[{w,i}]=max(pic,n_pic);
        
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
      return fn(w,wt,val,n,0);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
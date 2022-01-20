// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int v[], int n){
        
        // Your code here
        long long int ans=INT_MIN;
        long long int curr{};
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]>0)
            {
                f=1;
                break;
            }
            else{
                ans=max(ans,1LL*v[i]);
            }
        }
        if(!f)
        {
            return ans;
        }
        for(int i=0;i<n;i++)
        {
            curr+=v[i];
            // ans=max(ans,curr);
            if(curr<=0)
            {
                curr=0;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends
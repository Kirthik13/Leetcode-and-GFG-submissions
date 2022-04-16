// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long v[], int n, long long target)
	{
	    // Your code goes here
	    sort(v,v+n);
	    long long int ans{};
	    for(int i=0;i<n-2;i++)
	    {
	        int l=i+1,r=n-1;
	        while(l<r)
	        {
	            long long s=v[i]+v[l]+v[r];
	            if(s>=target)
	            {
	               // cout<<"i : "<<v[i]<<" j : "<<v[l]<<" k : "<<v[r]<<endl;
	               // cout<< " s  : "<<s<<endl;
	               // ans++;
	               // while(l+1<r and v[l]==v[l+1]) l++;
	               // while(l<r-1 and v[r]==v[r-1]) r--;
	               //l++;
	               //r--;
	               r--;
	               
	            }
	            else{
	                ans+=r-l;
	                l++;
	            }
	        }
	    }
	    return ans;
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends
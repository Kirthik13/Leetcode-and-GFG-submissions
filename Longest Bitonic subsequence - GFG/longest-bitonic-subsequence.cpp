// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>v)
	{
	    int n=v.size();
	    vector<int>dp1(n,1);
    vector<int>dp2(n,1);
    
    for(int i=1;i<n;i++)
    {
        for(int prev=i-1;prev>=0;prev--)
        {
            if(v[i]>v[prev])
            {
                dp1[i]=max(dp1[i],dp1[prev]+1);
            }
        }
    }
     for(int i=n-2;i>=0;i--)
    {
        for(int prev=i+1;prev<n;prev++)
        {
            if(v[i]>v[prev])
            {
                dp2[i]=max(dp2[i],dp2[prev]+1);
            }
        }
    }
//     for(auto &i:dp2) cout<<i<<" ";
    
    int ans=INT_MIN;
    for(int i=0;i<dp1.size();i++)
    {
        
        ans=max(ans,dp1[i]+dp2[i]-1);
    }
    return ans;
	    // code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int v[], int n, int k) {
       sort(v,v+n);

    
    int ans=v[n-1]-v[0];
    // int mi=;
    // int ma=v[n-1]-k;
    for(int i=0;i<n-1;i++)
    {
        int mi1=min(v[0]+k,v[i+1]-k);
        int ma1=max(v[n-1]-k,v[i]+k);
        if(mi1<0) continue;
        ans=min(ans,ma1-mi1);
    }
      
      return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
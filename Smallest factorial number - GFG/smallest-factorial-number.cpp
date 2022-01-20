// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    int canget(int n,int k)
{
    int i=5,c{};
    while(n/i>0)
    {
        c+=n/i;
        i*=5;
    }
    return c>=k;
}
        int findNum(int n)
        {
            if(n==1)
            {
                return 5;
            }
            int ans=INT_MAX;
    int l=1,r=5*n;
    while(l<=r)
    {
        int mid=l+((r-l)/2);

        if(canget(mid,n))
        {
            ans=mid;
            r=mid-1;
        }   
        else{
            l=mid+1;
        }
    }
    return ans;
        //complete the function here
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends
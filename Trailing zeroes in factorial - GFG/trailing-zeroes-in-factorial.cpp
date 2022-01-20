// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int fn(int n)
{
    int c{};
    int i=5;
    while(n/i>0)
    {
        c=c+n/i;
        i*=5;
    }
    return c;
}
    int trailingZeroes(int N)
    {
        int num=fn(N);
        
        return num;
        // Write Your Code here
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans  = ob.trailingZeroes(N);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends
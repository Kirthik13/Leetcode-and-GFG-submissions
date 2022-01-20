// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int v[], int n)
    {
        // coode here 
         int l=0,m=0,h=n-1;
    while(m<=h)
    {
        if(v[m]==0)
        {
            swap(v[m],v[l]);
            l++;
            m++;
        }
        else if(v[m]==1)
        {
            m++;
        }
        else{
            swap(v[m],v[h]);
            h--;
        }
    }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends
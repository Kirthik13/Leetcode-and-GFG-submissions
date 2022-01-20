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


    // int i, j, k;
    // int n1 = m - l + 1;
    // int n2 = r - m;

    // /* create temp arrays */
    // int L[n1], R[n2];

    // /* Copy data to temp arrays L[] and R[] */
    // for (i = 0; i < n1; i++)
    //     L[i] = arr[l + i];
    // for (j = 0; j < n2; j++)
    //     R[j] = arr[m + 1 + j];

    // /* Merge the temp arrays back into arr[l..r]*/
    // i = 0; // Initial index of first subarray
    // j = 0; // Initial index of second subarray
    // k = l; // Initial index of merged subarray

    // // Note the order of appearance of elements should
    // // be maintained - we copy elements of left subarray
    // // first followed by that of right subarray

    // // copy negative elements of left subarray
    // while (i < n1 && L[i] < 0)
    //     arr[k++] = L[i++];

    // // copy negative elements of right subarray
    // while (j < n2 && R[j] < 0)
    //     arr[k++] = R[j++];

    // // copy positive elements of left subarray
    // while (i < n1)
    //     arr[k++] = L[i++];

    // // copy positive elements of right subarray
    // while (j < n2)
    //     arr[k++] = R[j++];

void merge(int v[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
       int j=0;
    int k;
    int i=0;
    int L[n1],R[n2];

    for(i=0;i<n1;i++)
    {
        L[i]=v[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=v[m+j+1];
    }
    i=0;
    j=0;
    k=l;
 
    while(i<n1  and L[i]<0)
    {
        v[k++]=L[i++];
    }
    while(j<n2  and R[j]<0)
    {
        v[k++]=R[j++];
    }
    while(i<n1  )
    {
        v[k++]=L[i++];
    }
    // int j=0;
    while(j<n2  )
    {
        v[k++]=R[j++];
    }


}
void fn(int v[],int s,int n)
{
    if(s<n)
    {
        // return;
    int m=(s+n)/2;
    fn(v,s,m);
    fn(v,m+1,n);
    merge(v,s,m,n);
    }

}
void Rearrange(int v[], int n)
{
    // Your code goes here
        fn(v,0,n-1);

}
// { Driver Code Starts
#include <stdio.h>

void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}
// } Driver Code Ends


void rotate(int v[], int n)
{
    int t=v[0];
    int i=n-1;
    
 while(i>=0)
 {
     
 
    //  t=v[i+1];
     v[(i+1)%n]=v[i];
     i--;
 }
 v[1]=t;
}
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=(m-1)+(n-1);
        int r=min(m-1,n-1);
        
        double ans=1;
        int h=N-r+1;
        for(int i=1;i<=r;i++)
        {
            ans=ans*h/i;
            h++;
            
            
        }
        
        return (int)ans;
    }
};
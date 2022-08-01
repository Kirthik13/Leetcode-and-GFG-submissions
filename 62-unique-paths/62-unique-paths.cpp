class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=(m-1)+(n-1);
        int r=n-1;
        
        long long ans=1;

        long long int numerator=N-r+1;
        for(int i=1;i<=r;i++)
        {
            ans=ans*numerator/i;
            numerator++;
        }
        
        return ans;
    }
};
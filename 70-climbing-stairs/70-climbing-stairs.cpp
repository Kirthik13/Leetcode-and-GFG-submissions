class Solution {
public:
    map<int,int>dp;
    int fn(int i,int n)
    {
        if(i>n) return 0;
        if(i==n)
        {
            return 1;
        }
        if(dp.find(i)!=dp.end()) return dp[i];
        return dp[i]=fn(i+1,n)+fn(i+2,n);
    }
    int climbStairs(int n) {
        dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            
            dp[i]=(i+1<=n?dp[i+1]:0)+(i+2<=n?dp[i+2]:0);
        }
        return dp[0];
      // return fn(0,n);
    }
};
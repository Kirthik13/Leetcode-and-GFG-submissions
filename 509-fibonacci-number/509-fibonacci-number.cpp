class Solution {
public:
    int dp[1000000];
    int getx(int a)
    {
        return a*10000;
    }
    int fn(int n)
    {
        if(n<0) return 0;
        if(n<=1) return n;
        
        if(dp[getx(n)]!=-1) return dp[getx(n)];
        
        return dp[getx(n)]=fn(n-1)+fn(n-2);
    }
    int fib(int n) {
        
        memset(dp,-1,sizeof(dp));
        return fn(n);
        
    }
};
class Solution {
public:
    int dp[46];
    int climbstairs(int n) {
        if(n==0 ) return 1;
        if(n<0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        return dp[n]=climbstairs(n-1)+climbstairs(n-2);
    }
    int climbStairs(int n) {
       
        memset(dp,-1,sizeof(dp));
        return climbstairs(n);
    }
};
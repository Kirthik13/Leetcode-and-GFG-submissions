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
      return fn(0,n);
    }
};
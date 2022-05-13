class Solution {
public:
    int dp[10001][13];
    int fn(vector<int>& v, int amt,int n)
    {
        if(n==0 or amt==0)
        {
            if(amt==0) return 0;
            return INT_MAX-1;
        }
        if(dp[amt][n]!=-1) return dp[amt][n];
        
        if(v[n-1]>amt)
        {
            return dp[amt][n]=fn(v,amt,n-1);
        }
        return dp[amt][n]=min(1+fn(v,amt-v[n-1],n),fn(v,amt,n-1));
        
        
        
    }
    int coinChange(vector<int>& v, int amt) {
            memset(dp,-1,sizeof(dp));
    
        int ans=fn(v,amt,v.size());
       return ans==INT_MAX-1?-1:ans;
    }
};
class Solution {
public:
    int dp[10001];
    bool fn(vector<int>&v,int idx,int n)
    {
        if(idx==n-1) return 1;
        
        if(dp[idx]!=-1) return dp[idx];
        
        for(int i=1;i<=v[idx];i++)
        {
            if(fn(v,idx+i,n)) return dp[idx]=1;
        }
        
        return dp[idx]=0;
        
    }
    bool canJump(vector<int>& v) {
        int n=v.size();
        // vector<int>dp(n,-1);
        memset(dp,-1,sizeof(dp));
        return fn(v,0,n);
    }
};